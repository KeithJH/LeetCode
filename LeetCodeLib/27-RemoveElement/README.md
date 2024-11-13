# 27. Remove Element
## Goal
Given:
* `std::vector<int> &nums`
* `int val`

The goal is to modify `nums` in place such that all occurrences of `val` are removed in-place and
return the new logical size of `nums`.

## Solution
### Fill
Naive solution that searches linearly for each element that is not `val` and fills it into the next
location of `nums`. This likely will require more writes than necessary.

### Swap
Converge two pointers, one from the beginning and the other from the end, such that valid values
are swapped towards the beginning and invalid values are swapped to the end.

## Observations
