#include "Solutions.h"

namespace MinSubArrayLen
{
size_t SlidingSum::minSubArrayLen(const int target, const std::vector<int> &nums) const
{
	// Start at a larger-than-possible size for easy `min` calculations
	size_t minFoundLen = nums.size() + 1;

	int sum = 0;
	size_t start = 0;

	// Consider each element as the last of a sum
	for (size_t end = 0; end < nums.size(); end++)
	{
		sum += nums[end];

		// While the sum is larger or equal subtract elements off of the front of the sum
		// and adjust the minimum length found as necessary
		while (sum >= target)
		{
			minFoundLen = std::min(minFoundLen, end - start + 1);
			sum -= nums[start++];
		}
	}

	return minFoundLen > nums.size() ? 0 : minFoundLen;
}
} // namespace MinSubArrayLen
