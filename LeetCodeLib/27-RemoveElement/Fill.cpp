#include "Solutions.h"

namespace RemoveElement
{
size_t Fill::removeElement(std::vector<int> &nums, int val) const
{
	size_t fillIndex = 0;
	size_t searchIndex = 0;

	// Linearly search the vector
	while (searchIndex < nums.size())
	{
		// If the current search value is not the value to remove, move it to the next location to fill
		if (nums[searchIndex] != val)
		{
			nums[fillIndex++] = nums[searchIndex];
		}
		searchIndex++;
	}

	return fillIndex;
}
} // namespace RemoveElement
