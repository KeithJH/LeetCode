#include "Solutions.h"

namespace RemoveElement
{
size_t Swap::removeElement(std::vector<int> &nums, int val) const
{
	if (nums.size() == 0)
		return nums.size();

	std::ptrdiff_t fillIndex = 0;
	std::ptrdiff_t searchIndex = nums.size() - 1;

	while (searchIndex >= fillIndex)
	{
		// Look for the next element that should be swapped into the valid range
		if (nums[searchIndex] == val)
		{
			searchIndex--;
			continue;
		}

		// Look for the next element that should be swapped out of the valid range
		if (nums[fillIndex] == val)
		{
			std::swap(nums[fillIndex], nums[searchIndex]);
			searchIndex--;
		}
		fillIndex++;
	}

	return fillIndex;
}
} // namespace RemoveElement
