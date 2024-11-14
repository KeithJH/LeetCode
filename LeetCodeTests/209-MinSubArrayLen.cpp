#include <catch2/catch_all.hpp>
#include <vector>

#include "../LeetCodeLib/209-MinSubArrayLen/Solutions.h"

namespace MinSubArrayLen
{
TEST_CASE("MinSubArrayLen Given Tests", "[209][MinSubArrayLen]")
{
	MinSubArrayLen::BruteForce solver{};

	SECTION("Case 1") { REQUIRE(solver.minSubArrayLen(7, {2, 3, 1, 2, 4, 3}) == 2); }
	SECTION("Case 2") { REQUIRE(solver.minSubArrayLen(4, {1, 4, 4}) == 1); }
	SECTION("Case 3") { REQUIRE(solver.minSubArrayLen(11, {1, 1, 1, 1, 1, 1, 1, 1}) == 0); }
}
} // namespace MinSubArrayLen
