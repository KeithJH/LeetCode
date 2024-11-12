# 26. Remove Duplicates from Sorted Array
## Goal
Given:
* `std::vector<int> nums`: Sorted in non-decreasing order

The goal is to return the number of unique elements of `nums` and modify `nums` such that duplicates
are removed in-place.

## Solution
Vectors of 0 or 1 size already meet the criteria and can be used as is with the vector size. For larger
vectors we linearly search through the vector to find each unique element and put it into the correct
place. Since the data is already sorted we can say that an element is unique if it is different from the
previous element.

## Observations
