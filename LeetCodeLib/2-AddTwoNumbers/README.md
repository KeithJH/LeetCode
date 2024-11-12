# 2. Add Two Numbers
## Goal
Given:
* `ListNode` is defined as a linked list node that contains values between 0 and 9 representing
a non-negative integer in reverse order
* `ListNode *list1, *list2`

The goal is to calculate the sum of the two "integers" as represented in another `ListNode`.

## Solutions
### Iterative
Walk through both lists adding the "digits" and propagating a carry as necessary. Nothing
too fancy.

### Clean Iterative
Same general strategy but combines "phases" into a single loop.

### Recursive
Nothing special again, though less feasible with large sized inputs due to stack limits

## Observations
Comparisons were done on multiple dimensions, including platform (Windows versus WSL), compiler,
memory layout, solution, and of course input size (in terms of number of nodes for each list).

Detailed metrics can be found below for example test runs. For relative comparisons it shouldn't
matter much, but testing was done on a Ryzen 7700X. You can play around with results with:
```
$ ./out/build/linux-gcc-release/LeetCodeTests/LeetCodeTests --benchmark-no-analysis "[AddTwoNumbers][!benchmark]"
```

Windows results are indicated by runs with MSVC and Ubuntu (under WSL 2) with GCC. Clang-CL and
Clang++ did not show very different results and are not included for brevity.

### Memory Layout
The most interesting experiments were with memory layout, where input lists are created in one of
three ways. Regardless of method all operations still performed were done with the linked-list-like
structure, but there are still benefits to be gained from data locality and cache friendliness.

1. **thrashed new\***: List elements are allocated with `new ListNode()`, but irrelevant data is
allocated in-between each node to force data to be non-contiguous.
1. **default new\***: List elements are allocated with `new ListNode()`. It is possible that
allocations are contiguous, but not enforced.
1. **contiguous new[]**: List elements are allocated with `new ListNode[]`, enforcing elements to
be contiguous.

As expected, when memory is contiguous, even with linked-list-like operations, all solutions
perform much better. This is especially true compared to purposefully thrashed allocations.

### Solutions
#### Recursive
The data becomes a bit hard to compare as this solution does not scale due to stack size
limitations. At 10,000 elements, however, you can start to see that it's at least similar to the
other two solutions.

#### Iterative
As expected this is generally the best performing option and scales roughly linearly.

#### Clean Iterative
The difference between this and the original Iterative solution is fairly small and becomes even
less noticeable if memory is non-contiguous.

### Platform
#### Windows 11
Surprisingly runs with both MSVC and Clang-CL on these Windows 11 runs are noticeably slower than
any of the runs even under WSL on the same system.

Another thing that stands out here is that `new ListNode()` by default appears to give less
contiguous memory as there is substantial performance improvement by manually ensuring contiguous
node layout. There is still, however, additional performance degradation when thrashing the heap.

#### Ubuntu 22.04 (WSL 2)
Very good results outperforming the native Windows runs. It also appears that `new ListNode()` by
default was allocating more contiguous memory for us.

## Benchmark Results
### Time spent by Solution, Compiler, and Memory Layout for lists of 10,000 elements
|                     |      | thrashed new* | default new* | contiguous new[] |
|---------------------|------|---------------|--------------|------------------|
| **Iterative**       |      |               |              |                  |
|                     | msvc | 168.46 us     | 156.54 us    | 160.49 us        |
|                     | gcc  | 75.44 us      | 58.78 us     | 51.58 us         |
| **Clean Iterative** |      |               |              |                  |
|                     | msvc | 194.05 us     | 170.75 us    | 169.98 us        |
|                     | gcc  | 116.80 us     | 54.14 us     | 75.88 us         |
| **Recursive**       |      |               |              |                  |
|                     | msvc | 195.6 us      | 174.66 us    | 149.10 us        |
|                     | gcc  | 156.08 us     | 97.51 us     | 64.09 us         |

### Time spent by Solution, Compiler, and Memory Layout for lists of 2 million elements
|                     |      | thrashed new* | default new* | contiguous new[] |
|---------------------|------|---------------|--------------|------------------|
| **Iterative**       |      |               |              |                  |
|                     | msvc | 199.21 ms     | 62.17 ms     | 32.26 ms         |
|                     | gcc  | 125.76 ms     | 16.53 ms     | 16.11 ms         |
| **Clean Iterative** |      |               |              |                  |
|                     | msvc | 196.06 ms     | 61.17 ms     | 32.51 ms         |
|                     | gcc  | 125.81 ms     | 17.26 ms     | 17.39 ms         |

### Time spent by list size for Contiguous Iterative Solution
|   Size    |   Time    |
|-----------|-----------|
| 1         |   9.09 ns |
| 10        |  47.57 ns |
| 20        | 100.01 ns |
| 100       | 508.01 ns |
| 1,000     |   5.12 us |
| 10,000    |  51.13 us |
| 100,000   | 800.81 us |
| 1,000,000 |   9.80 ms |
| 2,000,000 |  20.66 ms |
