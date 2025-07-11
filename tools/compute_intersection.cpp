#include <limits>
#include <optional>
#include <string>

#include <CLI/CLI.hpp>
#include <fmt/format.h>
#include <range/v3/view/filter.hpp>
#include <spdlog/sinks/stdout_color_sinks.h>
#include <spdlog/spdlog.h>

#include "app.hpp"
#include "index_types.hpp"
#include "intersection.hpp"
#include "mappable/mapper.hpp"
#include "wand_data.hpp"
#include "wand_data_raw.hpp"

using namespace pisa;
using pisa::intersection::IntersectionType;
using pisa::intersection::Mask;

template <typename IndexType, typename WandType, typename QueryRange>
void intersect(
    IndexType const* index_ptr,
    std::optional<std::string> const& wand_data_filename,
    QueryRange&& queries,
    IntersectionType intersection_type,
    std::optional<std::uint8_t> max_term_count = std::nullopt
) {
    auto const& index = *index_ptr;

    WandType wdata;

    mio::mmap_source md;
    if (wand_data_filename) {
        std::error_code error;
        md.map(*wand_data_filename, error);
        if (error) {
            spdlog::error("error mapping file: {}, exiting...", error.message());
            std::abort();
        }
        mapper::map(wdata, md, mapper::map_flags::warmup);
    }

    std::size_t qid = 0U;

    auto print_intersection = [&](auto const& query, auto const& mask) {
        auto intersection = Intersection::compute(index, wdata, query, mask);
        std::cout << fmt::format(
            "{}\t{}\t{}\t{}\n",
            query.id() ? *query.id() : std::to_string(qid),
            mask.to_ulong(),
            intersection.length,
            intersection.max_score
        );
    };

    for (auto&& query: queries) {
        if (intersection_type == IntersectionType::Combinations) {
            for_all_subsets(query, max_term_count, print_intersection);
        } else {
            auto intersection = Intersection::compute(index, wdata, query);
            std::cout << fmt::format(
                "{}\t{}\t{}\n",
                query.id() ? *query.id() : std::to_string(qid),
                intersection.length,
                intersection.max_score
            );
        }
        qid += 1;
    }
}

using wand_raw_index = wand_data<wand_data_raw>;

int main(int argc, const char** argv) {
    spdlog::drop("");
    spdlog::set_default_logger(spdlog::stderr_color_mt(""));

    std::optional<std::uint8_t> max_term_count;
    std::size_t min_query_len = 0;
    std::size_t max_query_len = std::numeric_limits<std::size_t>::max();
    bool combinations = false;
    bool header = false;

    App<arg::Index, arg::WandData<arg::WandMode::Required>, arg::Query<arg::QueryMode::Unranked>, arg::LogLevel>
        app{"Computes intersections of posting lists."};
    auto* combinations_flag = app.add_flag(
        "--combinations", combinations, "Compute intersections for combinations of terms in query"
    );
    app.add_option(
           "--max-term-count,--mtc",
           max_term_count,
           "Max number of terms when computing combinations"
    )
        ->needs(combinations_flag);
    app.add_option("--min-query-len", min_query_len, "Minimum query length");
    app.add_option("--max-query-len", max_query_len, "Maximum query length");
    app.add_flag("--header", header, "Write TSV header");
    CLI11_PARSE(app, argc, argv);

    spdlog::set_level(app.log_level());

    auto queries = app.queries();
    auto filtered_queries = ranges::views::filter(queries, [&](auto&& query) {
        auto size = query.terms().size();
        return size < min_query_len || size > max_query_len;
    });

    if (header) {
        if (combinations) {
            std::cout << "qid\tterm_mask\tlength\tmax_score\n";
        } else {
            std::cout << "qid\tlength\tmax_score\n";
        }
    }

    IntersectionType intersection_type =
        combinations ? IntersectionType::Combinations : IntersectionType::Query;

    run_for_index(
        app.index_encoding(), MemorySource::mapped_file(app.index_filename()), [&](auto index) {
            using Index = std::decay_t<decltype(index)>;
            intersect<Index, wand_raw_index>(
                &index, app.wand_data_path(), filtered_queries, intersection_type, max_term_count
            );
        }
    );
}
