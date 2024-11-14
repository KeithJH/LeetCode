#include <catch2/catch_all.hpp>
#include <vector>

#include "../LeetCodeLib/209-MinSubArrayLen/Solutions.h"

namespace MinSubArrayLen
{
template <typename Solver> static void GivenTestCases(const Solver solver)
{
	SECTION("Case 1") { REQUIRE(solver.minSubArrayLen(7, {2, 3, 1, 2, 4, 3}) == 2); }
	SECTION("Case 2") { REQUIRE(solver.minSubArrayLen(4, {1, 4, 4}) == 1); }
	SECTION("Case 3") { REQUIRE(solver.minSubArrayLen(11, {1, 1, 1, 1, 1, 1, 1, 1}) == 0); }
}

template <typename Solver> static void AdditionalTestCases(const Solver solver)
{
	SECTION("Empty values") { REQUIRE(solver.minSubArrayLen(7, {}) == 0); }
	SECTION("Single value equal") { REQUIRE(solver.minSubArrayLen(7, {7}) == 1); }
	SECTION("Single value larger") { REQUIRE(solver.minSubArrayLen(6, {7}) == 1); }
	SECTION("Single value smaller") { REQUIRE(solver.minSubArrayLen(8, {7}) == 0); }
	SECTION("Large result") { REQUIRE(solver.minSubArrayLen(8, {1, 1, 1, 1, 1, 1, 1, 1, 0}) == 8); }
}

TEST_CASE("MinSubArrayLen Given Tests with Brute Force", "[209][MinSubArrayLen][BruteForce]")
{
	MinSubArrayLen::BruteForce solver{};
	GivenTestCases(solver);
}

TEST_CASE("MinSubArrayLen Additional Tests with Brute Force", "[209][MinSubArrayLen][BruteForce]")
{
	MinSubArrayLen::BruteForce solver{};
	AdditionalTestCases(solver);
}

TEST_CASE("MinSubArrayLen Given Tests with Sliding Sum", "[209][MinSubArrayLen][SlidingSum]")
{
	MinSubArrayLen::SlidingSum solver{};
	GivenTestCases(solver);
}

TEST_CASE("MinSubArrayLen Additional Tests with Sliding Sum", "[209][MinSubArrayLen][SlidingSum]")
{
	MinSubArrayLen::SlidingSum solver{};
	AdditionalTestCases(solver);
}
} // namespace MinSubArrayLen
