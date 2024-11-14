#include <catch2/catch_all.hpp>
#include <string>

#include "../LeetCodeLib/125-ValidPalindrome/Solutions.h"

namespace ValidPalindrome
{
TEST_CASE("ValidPalindrome Given Tests", "[125][ValidPalindrome]")
{
	ValidPalindrome::Solution solver{};

	SECTION("Case 1") { REQUIRE(solver.isPalindrome("A man, a plan, a canal: Panama")); }
	SECTION("Case 2") { REQUIRE_FALSE(solver.isPalindrome("race a car")); }
	SECTION("Case 3") { REQUIRE(solver.isPalindrome(" ")); }
}

TEST_CASE("ValidPalindrome Additional Tests", "[125][ValidPalindrome]")
{
	ValidPalindrome::Solution solver{};

	SECTION("Empty String") { REQUIRE(solver.isPalindrome("")); }
	SECTION("Single Space") { REQUIRE(solver.isPalindrome(" ")); }
	SECTION("Palindrome with upper-case") { REQUIRE(solver.isPalindrome("Racecar")); }
	SECTION("Palindrome with numeric") { REQUIRE(solver.isPalindrome("0P0")); }
	SECTION("Non-palindrome with numeric") { REQUIRE_FALSE(solver.isPalindrome("0P")); }
}
} // namespace ValidPalindrome
