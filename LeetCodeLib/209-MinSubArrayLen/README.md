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

### Sliding Sum
Consider each element of the data as the last element of a subarray sum, progressively adding its
value. Once the sum is larger or equal to the target number subtract out elements from the start of
the current subarray until the sum no longer meets the criteria. This is possible since all elements
are positive and removing elements is guaranteed to decrease the sum.

## Observations
