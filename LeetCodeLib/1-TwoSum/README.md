# 1. Two Sum
## Goal
Given:
* `std::vector<int> nums`
* `int target`

The goal is to return indices `a` and `b` such that:
* `nums[a] + nums[b] == target`
* `a != b`

## Solutions
### Brute Force
Likely the obvious solution where we expect to search through `nums` linearly for a pair `a` and `b`
that satisfies the goal. Nested `for` loops should make it clear this isn't going to be particularly
fast, but you can "optimize" the inner loop to start one past the current index of the outer loop.

### Avx2
Extends the Brute Force solution to use 256-bit SIMD instructions. While there are multiple approaches,
this keeps the outer loop the same and vectorizes the inner loop. The `target` is broadcasted to a SIMD
register, as is the value currently being evaluated by the outer loop. We can then load a SIMD register
the next inner loop values and perform the add to the outer (broadcasted) value followed by a compare
to the (broadcasted) `target`. Since we do not control the input, we are careful not to over read
`nums` and have special logic to potentially re-read the last portion of `nums` if necessary to
continue using SIMD instructions. Ensuring `a != b` requires a bit of care for that tail logic by
manipulating the equals mask to always have a `0` bit for that case.

Further things that could be interesting if we assumed we had control over memory allocation for
the inputs:
* Align data for aligned loads. This may not be as applicable with the current approach as our
starting index is moving by one element and not by the SIMD width.
* Allocate memory easily divisible by SIMD width to change special handling of tail behavior

### Avx512
Much the same as the Avx2 solution, but with larger 512-bit registers and instructions. Avx512 also
has an instruction that directly returns a mask from the comparison of registers.

### Hash Map
This is likely the expected solution, requiring a single pass over the data. When visiting each
value at index `i` we populate a hash map with that value and our current index. We can also
calculate the needed value to reach the target (`target - nums[i]`) and look-up if we've seen
that value in the same hash map. If we have, we've found the solution of our current index and
the index found from the hash map. One important note for this solution is that we now have to
consider the memory for the hash map. Even if the memory usage is acceptable, we can make sure that
we pre-reserve some memory to avoid multiple growths over the search. While fairly pessimistic one
solution is to just grow to the size of the `nums` vector.

# Observations
While the Hash Map solution is faster for larger arrays of integers, it should be noted that the
"simpler" options require less memory and can outperform for smaller data sets. This is especially
true if you allow the use of SIMD instructions such as in the Avx2/Avx512 solutions.

For simplicity the benchmark is fairly contrived with the solution always being the last two
indices as that is the worst case for all the approaches tested.

For relative comparisons it shouldn't matter much, but testing was done on a Ryzen 7700X. The most
important thing to note is that Avx512 is supported and performs well in this scenario, which may
not be the case for all processors.

Some output edited for further compactness:
```
$ ./out/build/linux-gcc-release/LeetCodeTests/LeetCodeTests --benchmark-no-analysis "[!benchmark][TwoSum]"
Randomness seeded to: 1157810821
```
```
-------------------------------------------------------------------------------
  Size: 2
-------------------------------------------------------------------------------
benchmark name                            samples    iterations          mean
-------------------------------------------------------------------------------
BruteForce                                     100          1767     9.2767 ns
Avx2                                           100          1668    9.57159 ns
Avx512                                         100          1647     9.8456 ns
HashMap                                        100           435    37.1544 ns
PreSizedHashMap                                100           553     25.943 ns
```
```
-------------------------------------------------------------------------------
  Size: 1000
-------------------------------------------------------------------------------
benchmark name                            samples    iterations          mean
-------------------------------------------------------------------------------
BruteForce                                     100             1    127.534 us
Avx2                                           100             1    26.1359 us
Avx512                                         100             1    16.8049 us
HashMap                                        100             1    25.7659 us
PreSizedHashMap                                100             1    20.0898 us
```
```
-------------------------------------------------------------------------------
  Size: 2000
-------------------------------------------------------------------------------
benchmark name                            samples    iterations          mean
-------------------------------------------------------------------------------
BruteForce                                     100             1    496.239 us
Avx2                                           100             1    102.449 us
Avx512                                         100             1    66.2157 us
HashMap                                        100             1    60.0121 us
PreSizedHashMap                                100             1     42.735 us
```
```
-------------------------------------------------------------------------------
  Size: 4000
-------------------------------------------------------------------------------
benchmark name                            samples    iterations          mean
-------------------------------------------------------------------------------
BruteForce                                     100             1    1.91709 ms
Avx2                                           100             1    378.888 us
Avx512                                         100             1    263.263 us
HashMap                                        100             1    136.078 us
PreSizedHashMap                                100             1    89.1744 us
```
```
-------------------------------------------------------------------------------
  Size: 8000
-------------------------------------------------------------------------------
benchmark name                            samples    iterations          mean
-------------------------------------------------------------------------------
BruteForce                                     100             1    8.59815 ms
Avx2                                           100             1    1.44708 ms
Avx512                                         100             1    1.05279 ms
HashMap                                        100             1    281.766 us
PreSizedHashMap                                100             1     193.92 us
```
