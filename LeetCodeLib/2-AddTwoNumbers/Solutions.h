#pragma once
#include <vector>

struct ListNode
{
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *nextNode) : val(x), next(nextNode) {}
};

namespace AddTwoNumbers
{
class Iterative
{
  public:
	ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) const;
};

class Recursive
{
  public:
	ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) const;
};
} // namespace AddTwoNumbers