#include <catch2/catch_all.hpp>
#include <vector>

#include "../LeetCodeLib/80-RemoveDuplicates2/Solutions.h"

namespace RemoveDuplicates2
{
static void TestCase(Solution solver, std::vector<int> &&input, std::vector<int> &&expectedResult)
{
	auto result = solver.removeDuplicates(input);
	REQUIRE(result == expectedResult.size());

	for (size_t i = 0; i < expectedResult.size(); i++)
	{
		CHECK(input[i] == expectedResult[i]);
	}
}

TEST_CASE("RemoveDuplicates2 Given Tests", "[80][RemoveDuplicates2]")
{
	RemoveDuplicates2::Solution solver{};

	SECTION("Case 1") { TestCase(solver, {1, 1, 1, 2, 2, 3}, {1, 1, 2, 2, 3}); }
	SECTION("Case 2") { TestCase(solver, {0, 0, 1, 1, 1, 1, 2, 3, 3}, {0, 0, 1, 1, 2, 3, 3}); }
}

TEST_CASE("RemoveDuplicates2 Additional Tests", "[80][RemoveDuplicates2]")
{
	RemoveDuplicates2::Solution solver{};

	SECTION("Empty data") { TestCase(solver, {}, {}); }
	SECTION("One Element") { TestCase(solver, {2}, {2}); }
	SECTION("Two Elements") { TestCase(solver, {2}, {2}); }
	SECTION("Duplicate at start") { TestCase(solver, {1, 1, 2}, {1, 1, 2}); }
	SECTION("Duplicate at end") { TestCase(solver, {1, 2, 2}, {1, 2, 2}); }
	SECTION("Triplicate at start") { TestCase(solver, {2, 2, 2, 3}, {2, 2, 3}); }
	SECTION("Triplicate at end") { TestCase(solver, {1, 2, 2, 2}, {1, 2, 2}); }
}
} // namespace RemoveDuplicates2
