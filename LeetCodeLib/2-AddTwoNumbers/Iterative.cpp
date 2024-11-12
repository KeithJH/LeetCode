#include "Solutions.h"

namespace AddTwoNumbers
{
int EvaluateSumSetCarry(int value, int &outCarry)
{
	outCarry = 0;
	if (value >= 10)
	{
		outCarry = 1;
		value -= 10;
	}

	return value;
}

ListNode *InsertListNode(ListNode *current, int nodeValue)
{
	ListNode *next = new ListNode(nodeValue);
	current->next = next;

	return next;
}

ListNode *Iterative::addTwoNumbers(ListNode *l1, ListNode *l2) const
{
	// These cases are specifically disallowed by the problem and are only "half" handled here.
	// This could be an issue if the caller expects a copy and this creates nuances around how
	// memory is expected to be freed.
	if (!l1)
		return l2;
	if (!l2)
		return l1;

	// List is already in "reverse" so we can start the addition with zero carry
	int carry = 0;
	ListNode *headNode = new ListNode(EvaluateSumSetCarry(l1->val + l2->val, carry));
	ListNode *currentNode = headNode;

	l1 = l1->next;
	l2 = l2->next;

	// For each pair of digits we add them together with any carry from the previous step
	while (l1 && l2)
	{
		int nodeValue = EvaluateSumSetCarry(l1->val + l2->val + carry, carry);
		currentNode = InsertListNode(currentNode, nodeValue);

		l1 = l1->next;
		l2 = l2->next;
	}

	// If one list is longer than the other we continue adding with it and any carry
	ListNode *restOfLists = l1 ? l1 : l2;
	while (restOfLists)
	{
		int nodeValue = EvaluateSumSetCarry(restOfLists->val + carry, carry);
		currentNode = InsertListNode(currentNode, nodeValue);

		restOfLists = restOfLists->next;
	}

	// Finally allow for the final carry to create a new digit
	if (carry)
	{
		currentNode = InsertListNode(currentNode, carry);
	}

	return headNode;
}
} // namespace AddTwoNumbers
