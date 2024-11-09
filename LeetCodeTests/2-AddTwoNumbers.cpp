#include <catch2/catch_all.hpp>

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

static ListNode *ListFromDigits(const std::vector<int> &digits)
{
	ListNode *list = nullptr;
	ListNode *previous = nullptr;

	for (const auto value : digits)
	{
		list = new ListNode(value, previous);
		previous = list;
	}

	return list;
}

static long ValueFromList(ListNode* list)
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

TEST_CASE("AddTwoNumbers Given Tests solved Iteratively", "[2][AddTwoNumbers][Iterative]")
{
	AddTwoNumbers::Iterative solver{};

	SECTION("Case 1")
	{
		ListNode *list1 = new ListNode(2, new ListNode(4, new ListNode(3)));
		ListNode *list2 = new ListNode(5, new ListNode(6, new ListNode(4)));

		auto result = solver.addTwoNumbers(&list1[0], &list2[0]);
		RequireListHasExpectedValues(result, {7, 0, 8});

		DeleteList(result);
		DeleteList(list1);
		DeleteList(list2);
	}

	SECTION("Case 2")
	{
		ListNode list1(0);
		ListNode list2(0);

		auto result = solver.addTwoNumbers(&list1, &list2);
		RequireListHasExpectedValues(result, {0});

		DeleteList(result);
	}

	SECTION("Case 3")
	{
		ListNode *list1 = new ListNode(
			9, new ListNode(9, new ListNode(9, new ListNode(9, new ListNode(9, new ListNode(9, new ListNode(9)))))));
		ListNode *list2 = new ListNode(9, new ListNode(9, new ListNode(9, new ListNode(9))));

		auto result = solver.addTwoNumbers(list1, list2);
		RequireListHasExpectedValues(result, {8, 9, 9, 9, 0, 0, 0, 1});

		DeleteList(list1);
		DeleteList(list2);
		DeleteList(result);
	}
}

// May eventually want to change this to run only explicitly with tag "[.]"
TEST_CASE("AddTwoNumbers Random Tests solved Iteratively", "[2][AddTwoNumbers][Iterative][Random]")
{
	auto list1Size = GENERATE(take(1, random(1, 18)));
	auto list2Size = GENERATE(take(1, random(1, 18)));

	auto list1Digits = GENERATE_COPY(take(100, chunk(list1Size, random(0, 9))));
	auto list2Digits = GENERATE_COPY(take(100, chunk(list2Size, random(0, 9))));

	ListNode *list1 = ListFromDigits(list1Digits);
	auto list1Value = ValueFromList(list1);

	ListNode *list2 = ListFromDigits(list2Digits);
	auto list2Value = ValueFromList(list2);

	AddTwoNumbers::Iterative solver{};
	auto result = solver.addTwoNumbers(list1, list2);
	long resultValue = ValueFromList(result);

	REQUIRE(list1Value + list2Value == resultValue);

	DeleteList(result);
	DeleteList(list1);
	DeleteList(list2);
}

} // namespace AddTwoNumbers
