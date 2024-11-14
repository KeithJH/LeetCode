#include "Solutions.h"

namespace MinSubArrayLen
{
size_t BruteForce::minSubArrayLen(const int target, const std::vector<int> &nums) const
{
	// Start at a larger-than-possible size for easy `min` calculations
	size_t minFoundLen = nums.size() + 1;

	// Go through each start index
	for (size_t start = 0; start < nums.size(); start++)
	{
		int sum = nums[start];
		size_t end = start + 1;
		size_t currentLength = 1;

		// Find the most suitable sum starting from the current index
		while (sum < target && end < nums.size() && currentLength < minFoundLen)
		{
			sum += nums[end++];
			currentLength++;
		}

		if (sum >= target && currentLength < minFoundLen)
		{
			minFoundLen = currentLength;
		}
	}

	return minFoundLen > nums.size() ? 0 : minFoundLen;
}
} // namespace MinSubArrayLen
