#include <algorithm>
#include <catch2/catch_all.hpp>
#include <numeric>
#include <unordered_map>
#include <vector>

#include "../LeetCodeLib/27-RemoveElement/Solutions.h"

namespace RemoveElement
{
template <typename Solver>
static void TestCase(const Solver solver, std::vector<int> &nums, const int toRemove,
                     const std::unordered_map<int, ptrdiff_t> &expectedCounts)
{
	size_t expectedResult = 0;
	expectedResult = std::accumulate(
		expectedCounts.cbegin(), expectedCounts.cend(), expectedResult,
		[](size_t sum, const std::map<int, ptrdiff_t>::value_type &element) { return sum + element.second; });
	auto result = solver.removeElement(nums, toRemove);

	REQUIRE(result == expectedResult);
	for (auto const [expectedValue, expectedCount] : expectedCounts)
	{
		CHECK(std::count(nums.cbegin(), nums.cbegin() + result, expectedValue) == expectedCount);
	}
}

template <typename Solver> static void GivenTestCases(Solver solver)
{
	SECTION("Case 1")
	{
		std::vector<int> input{3, 2, 2, 3};
		std::unordered_map<int, ptrdiff_t> expectedCounts{{2, 2}};

		TestCase(solver, input, 3, expectedCounts);
	}

	SECTION("Case 2")
	{
		std::vector<int> input{0, 1, 2, 2, 3, 0, 4, 2};
		std::unordered_map<int, ptrdiff_t> expectedCounts{{0, 2}, {1, 1}, {3, 1}, {4, 1}};

		TestCase(solver, input, 2, expectedCounts);
	}
}

template <typename Solver> static void AdditionalTestCases(Solver solver)
{
	SECTION("Empty input")
	{
		std::vector<int> input{};
		std::unordered_map<int, ptrdiff_t> expectedCounts{};

		TestCase(solver, input, 2, expectedCounts);
	}

	SECTION("Element not present")
	{
		std::vector<int> input{1, 2, 5, 4};
		std::unordered_map<int, ptrdiff_t> expectedCounts{{1, 1}, {2, 1}, {4, 1}, {5, 1}};

		TestCase(solver, input, 3, expectedCounts);
	}

	SECTION("Only element present")
	{
		std::vector<int> input{3, 3, 3, 3};
		std::unordered_map<int, ptrdiff_t> expectedCounts{};

		TestCase(solver, input, 3, expectedCounts);
	}
}

TEST_CASE("RemoveElement Given Tests solved with Fill", "[27][RemoveElement][Fill]")
{
	GivenTestCases(RemoveElement::Fill{});
}

TEST_CASE("RemoveElement Additional Tests solved with Fill", "[27][RemoveElement][Fill]")
{
	AdditionalTestCases(RemoveElement::Fill{});
}

TEST_CASE("RemoveElement Given Tests solved with Swap", "[27][RemoveElement][Swap]")
{
	GivenTestCases(RemoveElement::Swap{});
}

TEST_CASE("RemoveElement Additional Tests solved with Swap", "[27][RemoveElement][Swap]")
{
	AdditionalTestCases(RemoveElement::Swap{});
}
} // namespace RemoveElement
