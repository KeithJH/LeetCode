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
} // namespace RemoveDuplicates2
