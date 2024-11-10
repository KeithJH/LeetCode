#include "Solutions.h"

namespace AddTwoNumbers
{
static ListNode *addTwoNumbersInternal(ListNode *l1, ListNode *l2, int carry)
{
	if (!l1 && !l2 && !carry)
	{
		return nullptr;
	}

	int value1 = l1 ? l1->val : 0;
	int value2 = l2 ? l2->val : 0;

	int value = value1 + value2 + carry;
	carry = 0;
	if (value >= 10)
	{
		carry = 1;
		value -= 10;
	}

	l1 = l1 ? l1->next : nullptr;
	l2 = l2 ? l2->next : nullptr;

	if (l1 || l2 || carry)
	{
		return new ListNode(value, addTwoNumbersInternal(l1, l2, carry));
	}

	return new ListNode(value);
}

ListNode *Recursive::addTwoNumbers(ListNode *l1, ListNode *l2) const
{
	// These cases are specifically disallowed by the problem and are only "half" handled here.
	// This could be an issue if the caller expects a copy and this creates nuances around how
	// memory is expected to be freed.
	if (!l1)
		return l2;
	if (!l2)
		return l1;

	int value = l1->val + l2->val;
	int carry = 0;
	if (value >= 10)
	{
		carry = 1;
		value -= 10;
	}

	return new ListNode(value, addTwoNumbersInternal(l1->next, l2->next, carry));
}
} // namespace AddTwoNumbers
