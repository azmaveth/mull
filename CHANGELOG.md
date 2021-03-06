# Changelog

## [0.8.0] - 14 Oct 2020

- Implemented mutators for (almost) all C++ expressions [#577](https://github.com/mull-project/mull/issues/577)
- Print total execution time (regression) [#741](https://github.com/mull-project/mull/pull/741)
- Allow combined include-path + exclude-path (by [Joakim Nohlgård](https://github.com/gebart)) [#747](https://github.com/mull-project/mull/pull/747)
- Fix a possible infinite loop in SourceManager (by [Evan Lojewski](https://github.com/meklort)) [#748](https://github.com/mull-project/mull/pull/748)
- Add [CppUTest](http://cpputest.github.io) support (by [Oskari Mantere](https://github.com/OMantere)) [#750](https://github.com/mull-project/mull/pull/750)
- Fix ppc64le builds (by [Evan Lojewski](https://github.com/meklort)) [#751](https://github.com/mull-project/mull/pull/751)
- Added `-ld-preload` command line option (by [Joakim Nohlgård](https://github.com/gebart)) [#756](https://github.com/mull-project/mull/pull/756)
- Compilation database speedup (by [Joakim Nohlgård](https://github.com/gebart)) [#760](https://github.com/mull-project/mull/pull/760)
- LLVM 10 Support [#761](https://github.com/mull-project/mull/pull/761)
- LLVM 3.9, 4.0, and 5.0 no longer supported [#762](https://github.com/mull-project/mull/pull/762)
- Add command line option to configure timeout per test run [#772](https://github.com/mull-project/mull/pull/772)
- [All the changes](https://github.com/mull-project/mull/pulls?q=is%3Apr+merged%3A2020-03-25..2020-10-14)

## [0.7.0] - 24 Mar 2020

- Introduced online documentation https://mull.readthedocs.io/en/latest/
- Stable and nightly builds are now hosted on [Bintray](http://bintray.com/mull-project) [#676](https://github.com/mull-project/mull/pull/676)
- Ubuntu packages now can be installed/updated via `apt-get` https://mull.readthedocs.io/en/latest/Installation.html#install-on-ubuntu
- Also, packages are now smaller [#690](https://github.com/mull-project/mull/pull/690)
- Mull can read compilation flags from the bitcode file (`-grecord-command-line` compiler option) [#663](https://github.com/mull-project/mull/pull/663)
- Improve JUnit report integration [#660](https://github.com/mull-project/mull/pull/660)
- Added options to control capture of the stderr/stdout from test runs [#674](https://github.com/mull-project/mull/pull/674)
- Fixed a bug with junk detection not reading compilation database correctly [#679](https://github.com/mull-project/mull/pull/679)
- Revamped the logging mechanism [#655](https://github.com/mull-project/mull/pull/655)
- Show warning when there is no debug information [#654](https://github.com/mull-project/mull/pull/654)
- Logger has a debug option [#669](https://github.com/mull-project/mull/pull/669)
- Strict mode added: treat warnings as fatal errors [#673](https://github.com/mull-project/mull/pull/673)
- Work on the "white list" AST search has started [#677](https://github.com/mull-project/mull/pull/677)
- [All the changes](https://github.com/mull-project/mull/pulls?q=is%3Apr+merged%3A2019-12-15..2020-03-24)

## [0.6.1] - 14 Dec 2019

 - Moved `LogicalAndToOr` and `LogicalOrToAnd` to `experimental` group #638
 - `IDEReporter` now can also show killed mutants next to survived #640
 - Fixed an issue with the compilation database containing relative paths #637
 - Gained first proper integration tests #631
 - [All the changes](https://github.com/mull-project/mull/pulls?q=is%3Apr+merged%3A2019-12-04..2019-12-14)

## [0.6.0] - 04 Dec 2019

 - Switched to [libirm](https://github.com/mull-project/libirm) - generic library for LLVM mutations #566
 - Started building online documentation: https://mull.readthedocs.io
 - Introduce a more granular mutation operators: https://mull.readthedocs.io/en/latest/SupportedMutations.html
 - Fixed compilation database parsing issue #632 #629
 - Fixed gcc builds #630
 - Report warning when JIT cannot resolve undefined symbol #628
 - Added an option to whitelist mutants by paths (`-include-path=...`) #617
 - Added `-dry-run` options #616
 - Removed the old driver (`mull-driver`) #612
 - Added LLVM 9 support #609
 - Fixed a bug when even junk mutations were applied, resulting in a longer execution time #595
 - Sped up junk detection by an order of magnitude #582 
 - [All the changes](https://github.com/mull-project/mull/pulls?q=is%3Apr+merged%3A2019-08-29..2019-12-04)

## [0.5.0] - 28 Aug 2019

 - Print more info when original test fails #549
 - Reporting JSON to Mutation Testing Elements (initial support) #517, #507
 - Introduce `-exclude-path` option to filter mutations #553
 - Enable reporters configuration via `-reporters` option #555
 - Junk detection for the Scalar Value mutator #557
 - Junk detection for the Replace Assignment mutator #559
 - [All the changes](https://github.com/mull-project/mull/pulls?q=is%3Apr+merged%3A2019-08-11..2019-08-28)

## [0.4.0] - 11 Aug 2019

 - Fixed the original value use-after-free issue #532, #536
 - Automated release process on macOS #537
 - Fix incorrect handling of the NSW/NUW flags #540
 - Bring back abandoned sandbox approach #541, #542
 - Add LLVM 9 support #544
 - Include build date into the version info #546
 - Include Ubuntu 18.04 into release process #547
 - [All the changes](https://github.com/mull-project/mull/pulls?q=is%3Apr+merged%3A2019-06-03..2019-08-11)

## [0.3.0] - 02 Jun 2019

 - Add junk detection
   - AndOrReplacement #509
   - MathDiv #511
   - MathMul #511
   - ReplaceCall #512
 - Handle edge case for AND-OR mutator #501
 - Add better handling of edge cases when there is no debug information #519, #520, #524
 - Print more info when Junk Detector fails to parse a file #524
 - [All the changes](https://github.com/mull-project/mull/pulls?q=is%3Apr+merged%3A2019-05-03..2019-06-02)

## [0.2.0] - 02 May 2019

 - Add FreeBSD Package #503
 - Switch back to PackageMaker on macOS #504
 - Add internal target to validate mutants #500
 - Lots of refactoring
 - [All the changes](https://github.com/mull-project/mull/pulls?q=is%3Apr+merged%3A2019-04-03..2019-05-02)

## [0.1.0] - 02 Apr 2019

 - Initial Release

## [0.0.0] - 16 Apr 2016

 - Initial commit

