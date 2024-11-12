#include <catch2/catch_all.hpp>

#include "../LeetCodeLib/26-RemoveDuplicates/Solutions.h"

namespace RemoveDuplicates
{
TEST_CASE("RemoveDuplicates Given Tests", "[26][RemoveDuplicates]")
{
	RemoveDuplicates::Solution solver{};

	SECTION("Case 1")
	{
		std::vector<int> input{1, 1, 2};
		auto result = solver.removeDuplicates(input);

		REQUIRE(result == 2);
		REQUIRE(input[0] == 1);
		REQUIRE(input[1] == 2);
	}
	SECTION("Case 2")
	{
		std::vector<int> input{0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
		auto result = solver.removeDuplicates(input);

		REQUIRE(result == 5);
		REQUIRE(input[0] == 0);
		REQUIRE(input[1] == 1);
		REQUIRE(input[2] == 2);
		REQUIRE(input[3] == 3);
		REQUIRE(input[4] == 4);
	}
}
} // namespace RemoveDuplicates
