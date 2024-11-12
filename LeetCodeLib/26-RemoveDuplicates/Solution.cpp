#include "Solutions.h"

namespace RemoveDuplicates
{
	size_t Solution::removeDuplicates(std::vector<int> &nums) const
	{
		// Just return size if there are 0 or 1 elements
		if (nums.size() < 2)
		{
			return nums.size();
		}

		// Starting at the second element (the first is always in the correct place) find what value
		// should be present
		int fillIndex = 1;
		for (size_t searchIndex = 1; searchIndex < nums.size(); searchIndex++)
		{
			// If we're the same as the previously filled element we need to keep moving forward for the next
			// unique element
			if (nums[searchIndex] == nums[fillIndex - 1])
			{
				continue;
			}

			// This is our next unique element, so fill it in
			nums[fillIndex++] = nums[searchIndex];
		}

		return fillIndex;
	}
} // namespace RemoveDuplicates
