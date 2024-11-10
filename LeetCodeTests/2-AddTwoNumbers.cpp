#include <catch2/catch_all.hpp>
#include <list>

#include "../LeetCodeLib/2-AddTwoNumbers/Solutions.h"

namespace AddTwoNumbers
{
static void DeleteList(ListNode *list)
{
	while (list)
	{
		ListNode *tmp = list;
		list = list->next;

		delete tmp;
	}
}

static void RequireListHasExpectedValues(ListNode *list, const std::initializer_list<int> expectedValues)
{
	for (const auto expectedValue : expectedValues)
	{
		REQUIRE_FALSE(list == nullptr);
		REQUIRE(list->val == expectedValue);
		list = list->next;
	}

	REQUIRE(list == nullptr);
}

static ListNode *ListFromDigits(const std::vector<int> &digits, const std::size_t thrashSize = 0)
{
	ListNode *list = nullptr;
	ListNode *previous = nullptr;

	std::list<std::size_t> thrash;

	for (const auto value : digits)
	{
		list = new ListNode(value, previous);
		previous = list;

		for (std::size_t x = 0; x < thrashSize; ++x)
		{
			thrash.push_back(x);
		}
	}

	return list;
}

static ListNode *ArrayFromDigits(const std::vector<int> &digits)
{
	auto arrayOfListNodes = new ListNode[digits.size()];

	for (std::size_t i = 0; i < digits.size(); i++)
	{
		arrayOfListNodes[i].next = i + 1 < digits.size() ? &arrayOfListNodes[i + 1] : nullptr;
		arrayOfListNodes[i].val = digits[digits.size() - i - 1];
	}

	return arrayOfListNodes;
}

static long ValueFromList(ListNode *list)
{
	long resultValue = 0;
	long factor = 1;

	while (list)
	{
		resultValue += factor * list->val;
		list = list->next;
		factor *= 10;
	}

	return resultValue;
}

template <typename Solver>
static void AddTwoNumbersBasicTest(const Solver solver, const std::initializer_list<int> list1Digits,
                                   const std::initializer_list<int> list2Digits,
                                   const std::initializer_list<int> expectedResult)
{
	ListNode *list1 = ListFromDigits(list1Digits);
	ListNode *list2 = ListFromDigits(list2Digits);

	auto result = solver.addTwoNumbers(list1, list2);
	RequireListHasExpectedValues(result, expectedResult);

	DeleteList(result);
	DeleteList(list1);
	DeleteList(list2);
}

template <typename Solver> static void AddTwoNumbersBasicTests(const Solver solver)
{
	SECTION("Case 1") { AddTwoNumbersBasicTest(solver, {2, 4, 3}, {5, 6, 4}, {7, 0, 8}); }

	SECTION("Case 2") { AddTwoNumbersBasicTest(solver, {0}, {0}, {0}); }

	SECTION("Case 3") { AddTwoNumbersBasicTest(solver, {9, 9, 9, 9, 9, 9, 9}, {9, 9, 9, 9}, {8, 9, 9, 9, 0, 0, 0, 1}); }
}

template <typename Solver> static void AddTwoNumbersRandomTests(const Solver solver)
{

	auto list1Size = GENERATE(take(1, random(1, 18)));
	auto list2Size = GENERATE(take(1, random(1, 18)));

	auto list1Digits = GENERATE_COPY(take(100, chunk(list1Size, random(0, 9))));
	auto list2Digits = GENERATE_COPY(take(100, chunk(list2Size, random(0, 9))));

	ListNode *list1 = ListFromDigits(list1Digits);
	auto list1Value = ValueFromList(list1);

	ListNode *list2 = ListFromDigits(list2Digits);
	auto list2Value = ValueFromList(list2);

	auto result = solver.addTwoNumbers(list1, list2);
	long resultValue = ValueFromList(result);

	REQUIRE(list1Value + list2Value == resultValue);

	DeleteList(result);
	DeleteList(list1);
	DeleteList(list2);
}

TEST_CASE("AddTwoNumbers Given Tests solved Iteratively", "[2][AddTwoNumbers][Iterative]")
{
	AddTwoNumbers::Iterative solver{};
	AddTwoNumbersBasicTests(solver);
}

TEST_CASE("AddTwoNumbers Random Tests solved Iteratively", "[2][AddTwoNumbers][Iterative][Random]")
{
	AddTwoNumbers::Iterative solver{};
	AddTwoNumbersRandomTests(solver);
}

TEST_CASE("AddTwoNumbers Given Tests solved Iteratively (cleaner)", "[2][AddTwoNumbers][CleanIterative]")
{
	AddTwoNumbers::CleanIterative solver{};
	AddTwoNumbersBasicTests(solver);
}

TEST_CASE("AddTwoNumbers Random Tests solved Iteratively (cleaner)", "[2][AddTwoNumbers][CleanIterative][Random]")
{
	AddTwoNumbers::CleanIterative solver{};
	AddTwoNumbersRandomTests(solver);
}

TEST_CASE("AddTwoNumbers Given Tests solved Recursively", "[2][AddTwoNumbers][Recursive]")
{
	AddTwoNumbers::Recursive solver{};
	AddTwoNumbersBasicTests(solver);
}

TEST_CASE("AddTwoNumbers Random Tests solved Recursively", "[2][AddTwoNumbers][Recursive][Random]")
{
	AddTwoNumbers::Recursive solver{};
	AddTwoNumbersRandomTests(solver);
}

template <typename Solver>
static void AddTwoNumbersListBenchmark(Solver &solver, ListNode *list1, ListNode *list2,
                                       Catch::Benchmark::Chronometer &meter)
{
	std::vector<ListNode *> results;
	results.reserve(meter.runs());

	meter.measure([&solver, &results, &list1, &list2] {
		auto result = solver.addTwoNumbers(list1, list2);
		results.push_back(result);
		return result;
	});

	for (const auto &result : results)
	{
		DeleteList(result);
	}
}

TEST_CASE("AddTwoNumbers Benchmarks", "[2][AddTwoNumbers][!benchmark]")
{
	const int MAX_RECURSIVE_BENCH = 10'000;

	auto list1Size = GENERATE(1, 10, 20, 100, 1'000, 10'000, 100'000, 1'000'000, 2'000'000);

	DYNAMIC_SECTION("Size: " << list1Size)
	{
		auto list2Size = list1Size;

		auto list1Digits = GENERATE_COPY(take(1, chunk(list1Size, random(0, 9))));
		auto list2Digits = GENERATE_COPY(take(1, chunk(list2Size, random(0, 9))));

		AddTwoNumbers::Iterative iterativeSolver{};
		AddTwoNumbers::CleanIterative cleanIterativeSolver{};
		AddTwoNumbers::Recursive recursiveSolver{};

		// Test lists created calling `new ListNode`
		{
			ListNode *listFromNew1 = ListFromDigits(list1Digits);
			ListNode *listFromNew2 = ListFromDigits(list2Digits);

			BENCHMARK_ADVANCED("Iterative")(Catch::Benchmark::Chronometer meter)
			{
				AddTwoNumbersListBenchmark(iterativeSolver, listFromNew1, listFromNew2, meter);
			};

			BENCHMARK_ADVANCED("Clean Iterative")(Catch::Benchmark::Chronometer meter)
			{
				AddTwoNumbersListBenchmark(cleanIterativeSolver, listFromNew1, listFromNew2, meter);
			};

			if (list1Size <= MAX_RECURSIVE_BENCH)
			{
				BENCHMARK_ADVANCED("Recursive")(Catch::Benchmark::Chronometer meter)
				{
					AddTwoNumbersListBenchmark(recursiveSolver, listFromNew1, listFromNew2, meter);
				};
			}

			DeleteList(listFromNew1);
			DeleteList(listFromNew2);
		}

		// Test lists created calling `new ListNode` while thrashing the heap
		// to avoid contiguous memory
		{
			ListNode *listFromThrashedNew1 = ListFromDigits(list1Digits, 4);
			ListNode *listFromThrashedNew2 = ListFromDigits(list2Digits, 4);

			BENCHMARK_ADVANCED("Iterative (thrash heap for input)")(Catch::Benchmark::Chronometer meter)
			{
				AddTwoNumbersListBenchmark(iterativeSolver, listFromThrashedNew1, listFromThrashedNew2, meter);
			};

			BENCHMARK_ADVANCED("Clean Iter. (thrash heap for input)")(Catch::Benchmark::Chronometer meter)
			{
				AddTwoNumbersListBenchmark(cleanIterativeSolver, listFromThrashedNew1, listFromThrashedNew2, meter);
			};

			if (list1Size <= MAX_RECURSIVE_BENCH)
			{
				BENCHMARK_ADVANCED("Recursive (thrash heap for input)")(Catch::Benchmark::Chronometer meter)
				{
					AddTwoNumbersListBenchmark(recursiveSolver, listFromThrashedNew1, listFromThrashedNew2, meter);
				};
			}

			DeleteList(listFromThrashedNew1);
			DeleteList(listFromThrashedNew2);
		}

		// Test lists created from arrays (`new ListNode[]`)
		{
			auto listFromArray1 = ArrayFromDigits(list1Digits);
			auto listFromArray2 = ArrayFromDigits(list2Digits);

			BENCHMARK_ADVANCED("Iterative (contiguous input)")(Catch::Benchmark::Chronometer meter)
			{
				AddTwoNumbersListBenchmark(iterativeSolver, listFromArray1, listFromArray2, meter);
			};

			BENCHMARK_ADVANCED("Clean Iterative (contiguous input)")(Catch::Benchmark::Chronometer meter)
			{
				AddTwoNumbersListBenchmark(cleanIterativeSolver, listFromArray1, listFromArray2, meter);
			};

			if (list1Size <= MAX_RECURSIVE_BENCH)
			{
				BENCHMARK_ADVANCED("Recursive (contiguous input)")(Catch::Benchmark::Chronometer meter)
				{
					AddTwoNumbersListBenchmark(iterativeSolver, listFromArray1, listFromArray2, meter);
				};
			}

			delete[] listFromArray1;
			delete[] listFromArray2;
		}
	}
}
} // namespace AddTwoNumbers
