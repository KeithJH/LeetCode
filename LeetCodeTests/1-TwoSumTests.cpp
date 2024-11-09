#include <catch2/catch_all.hpp>

#include "../LeetCodeLib/1-TwoSum/Solutions.h"

namespace TwoSum
{
template <typename Solver> static void TwoSumTest(Solver &solver, const std::vector<int> &&values, const int target)
{
	auto result = solver.twoSum(values, target);

	REQUIRE(result.size() == 2);
	REQUIRE(result[0] <= values.size());
	REQUIRE(result[1] <= values.size());

	int sum = values[result[0]] + values[result[1]];
	REQUIRE(sum == target);
}

template <typename Solver> static void TwoSumGivenTests(Solver &solver)
{
	SECTION("Case 1")
	{
		TwoSumTest(solver, {2, 7, 11, 15}, 9);
	}
	SECTION("Case 2")
	{
		TwoSumTest(solver, {3, 2, 4}, 6);
	}
	SECTION("Case 3")
	{
		TwoSumTest(solver, {3, 3}, 6);
	}
	SECTION("Case 4")
	{
		TwoSumTest(solver, {-1, 5, 7, 3, -2}, 3);
	}
}

TEST_CASE("TwoSum Given Tests solved with BruteForce", "[1][TwoSum][BruteForce]")
{
	TwoSum::BruteForce solver{};
	TwoSumGivenTests(solver);
}

TEST_CASE("TwoSum Given Tests solved with HashMap", "[1][TwoSum][HashMap]")
{
	TwoSum::HashMap solver{};
	TwoSumGivenTests(solver);
}

TEST_CASE("TwoSum Given Tests solved with PreSizedHashMap", "[1][TwoSum][PreSizedHashMap]")
{
	TwoSum::PreSizedHashMap solver{};
	TwoSumGivenTests(solver);
}

TEST_CASE("TwoSum Given Tests solved with Avx2", "[1][TwoSum][Avx2]")
{
	TwoSum::Avx2 solver{};
	TwoSumGivenTests(solver);
}

TEST_CASE("TwoSum Given Tests solved with Avx512", "[1][TwoSum][Avx512]")
{
	TwoSum::Avx512 solver{};
	TwoSumGivenTests(solver);
}

TEST_CASE("TwoSum Benchmarks", "[1][TwoSum][!benchmark]")
{
	auto testCaseSize = GENERATE(2, 1'000, 2'000, 4'000, 8'000);

	DYNAMIC_SECTION("Size: " << testCaseSize)
	{
		// Commented code below would allow for random solutions, but for easier comparison the
		// last two indices are taken instead, as for all the current algorithms that is also the
		// worst case scenario.
		auto testCaseNums = GENERATE_COPY(take(1, chunk(testCaseSize, random(-INT_MAX/2, INT_MAX/2))));
		auto firstIndex = testCaseSize - 1; // GENERATE_COPY(take(1, random(0, testCaseSize - 1)));
		auto secondIndex = testCaseSize - 2; // GENERATE_COPY(take(1, random(0, testCaseSize - 1)));

		//if (firstIndex == secondIndex)
		//{
		//	secondIndex = firstIndex == 0 ? testCaseSize - 1 : 0;
		//}

		auto target = testCaseNums[firstIndex] + testCaseNums[secondIndex];

		TwoSum::BruteForce bruteForceSolver{};
		TwoSum::Avx2 avx2Solver{};
		TwoSum::Avx512 avx512Solver{};
		TwoSum::HashMap hashMapSolver{};
		TwoSum::PreSizedHashMap preSizedHashMapSolver(testCaseSize);

		BENCHMARK("BruteForce")
		{
			return bruteForceSolver.twoSum(testCaseNums, target);
		};

		BENCHMARK("Avx2")
		{
			return avx2Solver.twoSum(testCaseNums, target);
		};

		BENCHMARK("Avx512")
		{
			return avx512Solver.twoSum(testCaseNums, target);
		};

		BENCHMARK("HashMap")
		{
			return hashMapSolver.twoSum(testCaseNums, target);
		};

		BENCHMARK("PreSizedHashMap")
		{
			return preSizedHashMapSolver.twoSum(testCaseNums, target);
		};
	}
}
} // namespace TwoSum
