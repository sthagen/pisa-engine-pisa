# Change Log

All notable changes to PISA will be documented in this file.
The format of the changes starting from 0.9.0 is based on
[Keep a Changelog](https://keepachangelog.com/en/1.0.0/).

## [0.10.0](https://github.com/pisa-engine/pisa/releases/tag/v0.10.0)

### Fixed
- Quantize in range [1, 2^b) (#575)
- Build-system fixes (#588)

### Changed
- Require CMake 3.16 or higher (#583)
- Dynamic dispatch for block codecs (#579)
- Add virtual destructor to `PostingAcumulator` (#587)

## [0.9.0](https://github.com/pisa-engine/pisa/releases/tag/v0.9.0)

### Added

- Produce URLs and lexicons when partitioning (#356)
- Shard tools (#358)
- Verbose flag for BP (#362)
- `stem_queries` tool (#365)
- Allow for defining scorer parameters (#366)
- Compile Headers workflow (#375)
- Streaming index compression for block index (#384)
- Stream builder for quantized case (#391)
- Added kth_threshold tool (#406)
- Catch and log NoSuchFile error (#428)
- AOL query extractor (#296)
- Taily stats tool (#430)
- Return times when extracting taily scores (#452)
- Enable counting postings by term (#453)
- Extract maxscores (#454)
- Add patch for accepting non-trec identifiers from WARC files (#468)
- Whitespace tokenizer (#496)
- CLI option to configure log level (#497)
- Implement TextAnalyzer (#503)
- Selecting tokenizer at query time (#499)
- Support C++20 build
- Accumulator concept
- Allow for usage of system oneTBB library through `PISA_SYSTEM_ONETBB`
  CMake option
- Allow for system Boost installation
- Allow system CLI11

### Fixed

- Append sourcing setvars.sh to .bashrc
- Source setvars.sh when installing TBB from package
- Use TBB thread local storage (#378)
- Fix deprecated TBB calls (#387)
- Fix CLI issue where quantization is not considered (#389)
- Krovetz thread-safety #390
- Fix bug of top-k threshold task (#426)
- Fix BP memory issue (#424)
- Fix reading bytes from bit vector (#443)
- Add inline to free function in header (#466)
- Obey query term weights (#467)
- Fix threshold logic (#429)
- Fix log of zero (#510)
- Custom sift down for binary heap (#507)
- Rank start from 1 instead of 0 (#516)
- Use thread local, as opposed to static, lexer (#528)
- Remove UB and read-after-buffer in varintgb
- Migrate to mdBook documentation
- Fix unaligned read in bitvector
- Add stdc++fs to target_link_libraries for gcc < 9

### Changed

- Update TBB to the newest version of oneTBB
- Unify document reordering in one tool (#363)
- Refactor cursor interface (#376)
- Maxscore performance improvements (#395)
- More robust memory mapping (#370)
- Read collection with lexicon (#437)
- Modify count-postings tool (#450)
- Make parsing libraries private dependencies (#463)
- Multiply block max score by term weight in cursor (#474) (#488)
- Upgrade CLI11 to 2.3.2
- Upgrade spdlog to 1.11.0
- Upgrade libfmt to 9.1.0
- Upgrade range-v3 to 0.12.0
- Upgrade Google Benchmark to 1.7.1
- Upgrade to the latest Porter2 version
- Replace `boost::variant` with `std::variant`
- Replace `boost::filesystem` with `std::filesystem`

### Removed

- Remove optimal_hybrid_index (#412)
- Remove PSTL (#472)
- Remove std iterator (#487)
- Remove configuration.hpp

## 0.8.2

- cppcoreguidelines-pro-type-member-init (#349)
- Extract compression to headers (#350)
- Plaintext tokenizer (#351)

## 0.8.1

- Replace unnecessary raw loops (#338)
- Fix readability-braces-around-statements warnings (#340)
- Fix hicpp-use-auto warnings
- Revert "Fix hicpp-use-auto warnings"
- Fix hicpp-use-auto warnings (#341)
- [clang-tidy] hicpp-move-const-arg (#342)
- modernize-use-equals-default + modernize-use-using (#344)
- Readability implicit bool conversion (#345)
- Readability uppercase literal suffix (#346)
- hicpp-explicit-conversions (#347)
- Update CMakeLists.txt (#348)

## 0.8.0

- Binary lib (#312)
- Change default run name from "R0" to "PISA" (#314)
- 99% quantile in queries tool (#315)
- QLD fix (#316)
- Fix maskedvbyte and varintgb buffer initialization when encoding (#318)
- Thresholds (#320)
- Add support for rerunning unsafe queries (#319)
- Common CLI arguments (#313)
- Quantized index (#321)
- Clang format (#324)
- Support for clang-tidy (#326)
- Fix CLI in create_freq_index (#329)
- Finish clang-format and add Travis check (#327)
- Some minor fixes to quantization (#331)
- Small tweak to app (#333)
- Update bit_vector.hpp (#335)
- Removed almost all config (#330)
- drop default logger in create_freq_index (#334)
- Fix 336 (#337)

## 0.7.0

- Create FUNDING.yml
- Update README.md
- Update README.md
- Moved Funding.yml
- Update FUNDING.yml
- Compute norm_lens at run time (#220)
- Added term_count and collection_len (#221)
- Cleanup (#223)
- Update README.md
- Update README.md
- Update wand_data_compressed.hpp
- Rename PEF (#192)
- Docname & URL reordering scripts and docs (#232)
- Fix taat (#233)
- Small chances to taat (#234)
- Update tokenizer (#243)
- Update documentation (#239)
- Update query processing (#244)
- Bad alloc (#257)
- Intersection with terms (#253)
- Added sampling task (#266)
- Fix documentation (#269)
- Update parsing.md (#268)
- Fixed sampling (#271)
- Fix TBB leaks in tests (#272)
- Added terms len into wand file (#274)
- Fix MacOS build (#276)
- Update .travis.yml (#275)
- Update block_posting_list.hpp (#279)
- Simplify BMW flow (#282)
- Create generate_mapping_from_permutations.py (#283)
- logger to stderr (#284)
- Fixing static analyzer errors (#273)
- Fix rapidcheck compilation with GCC9 (#287)
- Implementation of multiple scorers (#285)
- Update compute_intersection.cpp
- Update compute_intersection.cpp
- Sampling (#289)
- Fix warnings (#292)
- Fix sampling (#295)
- Pass top-k queue to the query algorithm (#297)
- Update block skip logic (#300)
- Update maxscore_query.hpp (#301)
- Reverse url and update doclex order  (#302)
- Pass thresholds to heap (#304)
- Update invert.hpp (#307)
- Fix thresholds load (#308)
- Update topk_queue.hpp (#309)
- Count postings (#311)
- Added tool to map textual queries to our query ID format (#310)

## 0.6.6

- Fix: issue with using an old version of trecpp

## 0.6.5

- Added node_modules to gitignore
- Log stats on the inverted index (#208)
- Update TBB and PSTL (#211)
- Integrate new trecpp version (#210)
- Introduce error limit for gumbo (#213)
- Updated CLI11 (#212)
- Update trecpp (#214)
- Fix sorting term bug (#209)
- Fix memory leak in cleantext (#215)
- Add run_id (#216)

## 0.6.4

- Update README.md
- Update README.md
- Update recursive_graph_bisection.cpp (#202)
- Update recursive_graph_bisection.cpp (#204)

## 0.6.3

- Fix python script to read the collection (#197)

## 0.6.2

- Removed external/te

## 0.6.1

- Fix logger names (#195)
- Update create_wand_data.cpp (#193)

## 0.6.0

- Create pull_request_template.md
- Create pull_request_template.md
- Delete pull_request_template.md
- Update README.md
- Update index.rst
- Update index.rst
- BMA Clean (#191)

## 0.5.0

- Moved files
- Parsing Washington Post format (#189)
- Upgrade wapopp (#190)

## 0.4.0

- Block params (#187)
- Sharding forward index (#106)

## 0.3.1

- Patch extract query (#186)

## 0.3.0

- Parallel evaluate (#181)

## 0.2.0

- Create CONTRIBUTING.md
- Added Contributing link
- Update README.md
- Implement tokenizer and use for query parsing. (#178)
- Update default params for bmw25 to b=0.4 and k1=0.9 (#171)

## 0.1.0

- Initial commit
- README
- Initial import
- Fix submodule repos and README
- Fix build instructions
- Singleton blocks
- Implement random shuffling of docids
- fix
- Remove semiasync_queue from freq_index
- Start using task_region
- Implement parallel superblock optimization
- Add benchmarks
- fixes
- Missing includes
- VBMW implementation
- Modified README.md
- Fixed authors order
- Update index_types.hpp
- Delete elias_fano_score.hpp
- Removed unused code
- Update succinct
- Updated stxxl
- Fix in NextGeq and Reset in wand_data_compressed
- Added clang format
- Big refactor of the folder structure
- Updated dependency and improved Readme
- Code improved
- Updated .gitignore
- Removed typedefs if favour of aliases
- removed extra spaces
- Added cxxopts dep and used in create_freq_index
- K taken as a CLI parameter with a fallback to configuration
- Moved topk_queue to a separate file
- Renamed to score_opt_partition.hpp
- Small fixes to topk_queue
- Updated Readme to be more concise
- Set CMAKE_RUNTIME_OUTPUT_DIRECTORY
- Fix in --check argument
- Added virtual d-tor
- Set output path for test binaries
- Fixed has_next_geq type_trait to use SFINAE correctly
- Re-organized source code
- Removed Singleton blocks in all_ones_sequences
- Added travis file
- Added build badge
- Added codecov (#10)
- Limited branches for CI to master only
- Project renamed
- Updated badges
- Improved portability and removed user_time (#13)
- Portability (#14)
- Updated FastPFor
- Removed succinct dependency (#12)
- Removed authors
- Removed union in favour of boost::variant (#20)
- Added streamvbyte & maskedvbyte (#21)
- Code cleanup (#22)
- Rm succinct (#24)
- Update Title (#25)
- Update .clang-format (#19)
- Update CMakeLists.txt (#26)
- Update README.md
- Updated FastPFor (#29)
- Qmx (#30)
- Qmx (#31)
- Added filter query script (#32)
- Added VarintGB (#33)
- Added Simple8b (#34)
- Added simd binary packing (#35)
- BMM implementation (#36)
- Fix AND query (#37)
- CLI11 (#39)
- Added Simple16 codec (#18)
- Revert "Added Simple16 codec (#18)" (#40)
- Simple16 (#41)
- Rebranding
- Update semiasync_queue.hpp
- Update README.md
- Update shuffle_docids.cpp
- Create evaluate_collection_ordering.cpp
- Update CMakeLists.txt
- Update GCC to 7 (#11)
- Suppressed warnings (#13)
- Network approach to BP algorithm (#10)
- Create Recursive_Graph_Bisection.md (#17)
- Top-k heap performance (Issue #15) (#16)
- Removed boost task_group in favour of TBB (#20)
- Mio (#21)
- Support thresholds for query performance tests
- Program to calculate top-k score thresholds
- Threshold computation prgoram in CMake
- Added catch2
- Migrated all tests
- Removed test with external file
- Test showing the problem in #26 (#33)
- Fix BMM (#32)
- Replaced progress logger with progress bar
- Removed boost as a system dependency (#34)
- Added clang (#36)
- Cleanup [ci skip] (#42)
- Upgrade to C++17 (#44)
- Removed m_terms (unused) (#49)
- Merge remote-tracking branch 'origin/master' into thresholds
- Thresholds for test queries
- Update CMakeLists.txt
- Update thresholds.cpp
- Added Clang 5/6 and GCC 8 on Linux
- Update README.md (#56)
- Parsing (#37)
- Threshold for correctness testing
- General cleanup (#64)
- Dead code block #65
- Moved to std optional
- Name fixes
- Support parallel tests by using generated temp directories (#70)
- Drop logger() in favor of spdlog
- Add missing {}'s
- Ranked OR TAAT (#73)
- Expose Catch2 test cases to ctest (#69)
- Removed unused variable
- Travis cache (#77)
- Add fmt and timer
- Move timer to `pisa`
- Added issue templates and code of conduct (#83)
- Travis build in parallel (#86)
- Added progress bar (#85)
- Update issue templates (#84)
- Created docs to specify the format of the indexes (#46)
- Test pisa header files for self-sufficiency (#82)
- Lazy accumulator (#88)
- Add range-v3 and remove `enumerate` with `view::iota` (#92)
- Create Query_Algorithms.md (#18)
- Produce document sizes file (#94)
- Cache build/external (#95)
- Create Index_Compression.md (#19)
- Terms with map (#97)
- Update README.md (#103)
- Tool for evaluating queries (#100)
- Clean up parse_collection
- Update warcpp
- Modify warc parsing function to reflect changes in wracpp
- Update LICENSE (#109)
- Added initial documentation (#110)
- Docs (#111)
- Docs (#114)
- Docs (#115)
- Update README.md
- Update README.md
- Update README.md
- Update index.rst
- Create getting-started.rst
- Create parsing.rst
- Create compress-index.rst
- Create query-index.rst
- Create document_reordering.rst
- Rename getting-started.rst to getting_started.rst
- Update and rename compress-index.rst to compress_index.rst
- Rename query-index.rst to query_index.rst
- Update document_reordering.rst
- Update index.rst
- Clean up parse_collection (#107)
- Update document_reordering.rst
- Delete Recursive_Graph_Bisection.md
- Rename Indexes_Format.md to index_format.md
- Update conf.py
- Update index.rst
- Delete Queries.md
- Update and rename query_index.rst to query_index.md
- Delete Query_Algorithms.md
- Update query_index.md
- Delete Compression_Algorithms.md
- Update compress_index.rst
- Update query_index.md
- Update README.md
- Update and rename getting_started.rst to getting_started.md
- Update README.md
- Update and rename document_reordering.rst to document_reordering.md
- Rename compress_index.rst to compress_index.md
- Update conf.py
- Update warcpp
- Remove regex
- Merge remote-tracking branch 'origin/master' into warc
- Pisa (#116)
- Range query (#108)
- Update compress_index.md
- Update compress_index.md
- Update compress_index.md
- Update compress_index.md
- Update compress_index.md
- Update compress_index.md
- Update compress_index.md
- Update document_reordering.md
- Update compress_index.md
- Update query_index.md
- Update index.rst
- Update index.rst
- Update index.rst
- Update index.rst
- Update index.rst
- Update index.rst
- Update getting_started.md
- Update index.rst
- Update README.md
- Cleanup (#120)
- Upgrade warcpp
- Upgrade warcpp
- Fix merging swapping problem
- Update parsing documentation
- Improving merging performance + debug logging with `--debug`
- Remove HTTP header when parsing HTML
- Dereference subcommand.
- Cli lambda (#122)
- Pass max_docid in call operator (#124)
- Update README.md
- Query algo (#123)
- Truncate clueweb1k.plaintext (#131)
- Reuse index across ranked queries tests for speedup (#132)
- Fix #128
- Support trecweb record format
- Upgrade trecpp to master
- Extracting query times
- Write logs to stderr and add --silent
- Update docs
- Added wand data range-based (#74)
- Update conf.py
- Update conf.py
- Create requirements.readthedocs.txt
- Fix CLI `needs` clause
- Update index_format.md
- Network BP (#141)
- Update ranked_and_query.hpp (#144)
- Add ranked_and into queries.cpp
- Fix issue with per-query timings
- Trectext (#153)
- Added Krovetz stemmer
- Added Krovetz to query processing and updated documentation
- Updated Krovetz
- Fix nostem in threshold
- Update the heap (#158)
- Deps update (#157)
- Fix Stemmer
- Update trecpp
- Fix stemmer
- Add heap score check to accumulation of top-k heap (#149)
- Stopwords (#154)
- Update invert.hpp (#161)
- Update .travis.yml
- Update .travis.yml
- Update .travis.yml
- Update .travis.yml
- Update .travis.yml
- Update .travis.yml
- Update .travis.yml
- Update .travis.yml
- Update .travis.yml
- Fix query lowercase (#166)
- Extract TREC topic (#165)
- Added algorithm to evaluate_query (#168)
- Bug fix (#169)
- Revert "Bug fix (#169)"
- Revert "Added algorithm to evaluate_query (#168)"
- Update ranked_or_query.hpp
- Select algorithm to use (#170)
- Update maxscore_query.hpp
- Update block_max_maxscore_query.hpp
- Update simple_accumulator.hpp
- Fix log message (#174)
