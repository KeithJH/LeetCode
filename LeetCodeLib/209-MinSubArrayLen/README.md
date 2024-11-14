# 209. Minimum Size Subarray Sum
## Goal
Given:
* `int target`: Positive integer
* `std::vector<int> &nums`: Positive integers

Return the minimal length of a subarray that has a sum greater than or equal to target. If no subarray
meets that criteria return 0 instead.

## Solution
### Brute Force
Analyze each starting index and calculate how long of a subarray is necessary to have a sum larger or
equal to the target value. If at any point the partial subarray is already longer than the minimum
length already found skip to the next starting index.

## Observations
