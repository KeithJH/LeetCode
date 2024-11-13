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
} // namespace ValidPalindrome
