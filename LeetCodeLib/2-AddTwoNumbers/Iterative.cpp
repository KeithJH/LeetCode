#include "Solutions.h"

namespace AddTwoNumbers
{
ListNode *Iterative::addTwoNumbers(ListNode *l1, ListNode *l2) const
{
	// These cases are specifically disallowed by the problem and are only "half" handled here.
	// This could be an issue if the caller expects a copy and this creates nuances around how
	// memory is expected to be freed.
	if (!l1)
		return l2;
	if (!l2)
		return l1;

	return nullptr;
}
} // namespace AddTwoNumbers
