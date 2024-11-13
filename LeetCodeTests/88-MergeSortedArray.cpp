#include <catch2/catch_all.hpp>

#include "../LeetCodeLib/88-MergeSortedArray/Solutions.h"

namespace MergeSortedArray
{
TEST_CASE("MergeSortedArray Given Tests", "[88][MergeSortedArray]")
{
	MergeSortedArray::Solution solver{};

	SECTION("Case 1")
	{
		std::vector<int> nums1{1, 2, 3, 0, 0, 0};
		std::vector<int> nums2{2, 5, 6};
		solver.merge(nums1, 3, nums2, 3);

		std::vector<int> expectedResult = {1, 2, 2, 3, 5, 6};
		REQUIRE(nums1.size() == expectedResult.size());

		for (size_t i = 0; i < expectedResult.size(); i++)
		{
			CHECK(nums1[i] == expectedResult[i]);
		}
	}

	SECTION("Case 2")
	{
		std::vector<int> nums1{1};
		std::vector<int> nums2{};
		solver.merge(nums1, 1, nums2, 0);

		std::vector<int> expectedResult = {1};
		REQUIRE(nums1.size() == expectedResult.size());

		for (size_t i = 0; i < expectedResult.size(); i++)
		{
			CHECK(nums1[i] == expectedResult[i]);
		}
	}

	SECTION("Case 3")
	{
		std::vector<int> nums1{0};
		std::vector<int> nums2{1};
		solver.merge(nums1, 0, nums2, 1);

		std::vector<int> expectedResult = {1};
		REQUIRE(nums1.size() == expectedResult.size());

		for (size_t i = 0; i < expectedResult.size(); i++)
		{
			CHECK(nums1[i] == expectedResult[i]);
		}
	}
}
} // namespace MergeSortedArray
