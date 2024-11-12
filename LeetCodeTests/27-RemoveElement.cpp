#include <algorithm>
#include <catch2/catch_all.hpp>
#include <vector>

#include "../LeetCodeLib/27-RemoveElement/Solutions.h"

namespace RemoveElement
{
TEST_CASE("RemoveElement Given Tests", "[27][RemoveElement]")
{
	RemoveElement::Solution solver{};

	SECTION("Case 1")
	{
		std::vector<int> input{3, 2, 2, 3};
		auto result = solver.removeElement(input, 3);

		REQUIRE(result == 2);
		CHECK(input[0] == 2);
		CHECK(input[1] == 2);
	}

	SECTION("Case 2")
	{
		std::vector<int> input{0, 1, 2, 2, 3, 0, 4, 2};
		auto result = solver.removeElement(input, 2);

		REQUIRE(result == 5);
		CHECK(std::count(input.cbegin(), input.cbegin() + result, 0) == 2);
		CHECK(std::count(input.cbegin(), input.cbegin() + result, 1) == 1);
		CHECK(std::count(input.cbegin(), input.cbegin() + result, 3) == 1);
		CHECK(std::count(input.cbegin(), input.cbegin() + result, 4) == 1);
	}
}
} // namespace RemoveElement
