# LeetCode
## Purpose
Explore LeetCode problems, often implementing multiple solutions to compare. More detailed notes
per problem can be found in the respective solution directories and may vary in "completeness" as
they are meant more as personal notes. They may still have some interesting observations, however.

## Dependencies
* CMake
* vcpkg
* Catch2 (fetched via vcpkg)

## Structure
Solutions are provided in the LeetCodeLib project, with a sub-directory for each problem. At
minimum the given test cases are in the LeetCodeTests project, potentially with additional tests
and even benchmarks.

Projects use CMake, so building and running can follow the usual flow such as:
```
$ cmake --preset linux-gcc-release
$ cmake --build out/build/linux-gcc-release/
$ ctest --test-dir out/build/linux-gcc-release/
```

More control of tests, and benchmarks, is easily accomplished manually running the generated test
binary with any of the controls provided by Catch2 (some examples given below).
```
$ ./out/build/linux-gcc-release/LeetCodeTests/LeetCodeTests [--skip-benchmarks] [--benchmark-no-analysis] ["some fileter"]
```

## Note
Some solutions may expect certain hardware/features (like various SIMD instruction sets) and little
to no effort is currently spent handling their absense gracefully.
