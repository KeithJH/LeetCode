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

static void RequireListHasExpectedValues(ListNode *list, std::initializer_list<int> expectedValues)
{
	for (const auto expectedValue : expectedValues)
	{
		REQUIRE_FALSE(list == nullptr);
		REQUIRE(list->val == expectedValue);
		list = list->next;
	}

	REQUIRE(list == nullptr);
}

TEST_CASE("AddTwoNumbers solved Iteratively", "[2][AddTwoNumbers][Iterative]")
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
} // namespace AddTwoNumbers
