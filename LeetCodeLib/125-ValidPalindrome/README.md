# 125. Valid Palindrome
## Goal
Given:
* `std::string s`

Return true if `s` is a palindrome, false otherwise. The comparison is case-insensitive, with all
uppercase letters coverted to lowercase, and all non-alphanumeric characters removed.

## Solution
Start two iterators from either end of the string and move inwards skipping any non-alphanumeric
characters. If any pair of values are not equal the string is not a palindrome. Once the two iterators
cross each other there are no other chances that the string is not.

## Observations
