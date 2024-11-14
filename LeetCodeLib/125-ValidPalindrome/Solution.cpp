#include "Solutions.h"

namespace ValidPalindrome
{
// ASCII range is in the order: _, 0 - 9, _, A - Z, _, a - z, _
bool isUpperCase(const char c) { return c >= 'A' && c <= 'Z'; }

bool isLowerCase(const char c) { return c >= 'a' && c <= 'z'; }

bool isNumeric(const char c) { return c >= '0' && c <= '9'; }

bool isAlphaNumeric(const char c) { return isUpperCase(c) || isLowerCase(c) || isNumeric(c); }

bool Solution::isPalindrome(const std::string s) const
{
	// No need to process strings of 1 or 0 length as they are always palindromes
	if (s.size() < 2)
	{
		return true;
	}

	// Keep track of an iterator at the start and end
	auto front = s.begin();
	auto back = s.end() - 1;

	// Continue searching until the iterators pass each other
	while (front < back)
	{
		// Find the next alpha-numeric from the start
		if (!isAlphaNumeric(*front))
		{
			front++;
			continue;
		}

		// Find the next alpha-numeric from the end
		if (!isAlphaNumeric(*back))
		{
			back--;
			continue;
		}

		// Convert to ASCII lower case
		constexpr int lowerOffset = 'a' - 'A';
		const auto frontValue = isUpperCase(*front) ? *front + lowerOffset : *front;
		const auto backValue = isUpperCase(*back) ? *back + lowerOffset : *back;

		// If they are not the same the string is not a palindrome
		if (frontValue != backValue)
		{
			return false;
		}

		// Move the iterators towards each other
		front++;
		back--;
	}

	return true;
}
} // namespace ValidPalindrome
