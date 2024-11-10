#include "Solutions.h"

namespace AddTwoNumbers
{
ListNode *CleanIterative::addTwoNumbers(ListNode *l1, ListNode *l2) const
{
	// These cases are specifically disallowed by the problem and are only "half" handled here.
	// This could be an issue if the caller expects a copy and this creates nuances around how
	// memory is expected to be freed.
	if (!l1)
		return l2;
	if (!l2)
		return l1;

	int carry = 0;
	int nodeValue = l1->val + l2->val;
	if (nodeValue >= 10)
	{
		nodeValue -= 10;
		carry = 1;
	}

	ListNode *headNode = new ListNode(nodeValue);
	ListNode *currentNode = headNode;

	l1 = l1->next;
	l2 = l2->next;

	while (l1 || l2 || carry)
	{
		int value1 = l1 ? l1->val : 0;
		int value2 = l2 ? l2->val : 0;

		nodeValue = value1 + value2 + carry;
		carry = 0;
		if (nodeValue >= 10)
		{
			nodeValue -= 10;
			carry = 1;
		}

		ListNode *next = new ListNode(nodeValue);
		currentNode->next = next;
		currentNode = next;

		l1 = l1 ? l1->next : nullptr;
		l2 = l2 ? l2->next : nullptr;
	}

	return headNode;
}
} // namespace AddTwoNumbers
