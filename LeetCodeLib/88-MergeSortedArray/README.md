# 88. Merge Sorted Array
## Goal
Given:
* `std::vector<int> &nums1`
* `int m`: logical size of `nums1`
* `std::vector<int> &nums2`
* `int n`: logical size of `nums2`

The goal is to modify `nums1` in place such that all elements of `nums1` and `nums2` are sorted in
non-decreasing order. Note that `nums1` is already sized to store all the necessary values and
contains zeros in the indexes beyond the first `m` elements.

## Solution
Merge the two vectors starting from the end. Since `nums1` and `nums2` are already sorted we only
need to compare the last unused value for each to find the larger of the two, which should go into
whatever index we are currently filling.

## Observations
