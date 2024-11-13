#include "Solutions.h"

namespace RemoveDuplicates2
{
size_t Solution::removeDuplicates(std::vector<int> &nums) const
{
	// With two of fewer elements the data cannot have more than two duplicates
	if (nums.size() <= 2)
	{
		return nums.size();
	}

	size_t elementCount = 1;
	size_t fillIndex = 1;

	// Walk through each element of the array
	for (size_t i = 1; i < nums.size(); i++)
	{
		// Keep track of how many duplicates there are
		if (nums[i] == nums[i - 1])
		{
			elementCount++;
		}
		else
		{
			elementCount = 1;
		}

		// Only use the element if it does not exceed the maximum duplicate count
		if (elementCount <= 2)
		{
			nums[fillIndex] = nums[i];
			fillIndex++;
		}
	}

	return fillIndex;
}
} // namespace RemoveDuplicates2
