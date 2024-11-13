# 80. Remove Duplicates from Sorted Array II
## Goal
Given:
* `std::vector<int> &nums`: Data sorted in non-decreasing order

Modify `nums` in place such that each element is present at most twice, returning the logical size.

## Solution
Walk through the data linearly and keep track of the amount of duplicates of the current value,
leveraging the fact that since they are sorted they will be contiguous. If the occurrence of that
value does not exceed the maximum number of duplicates place it back in the data.

## Observations
