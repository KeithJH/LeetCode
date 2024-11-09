#include <vector>

#include "Solutions.h"

namespace TwoSum
{
std::vector<std::size_t> BruteForce::twoSum(const std::vector<int> &nums, const int target) const
{
	for (std::size_t i = 0; i < nums.size() - 1; i++)
	{
		for (std::size_t j = i + 1; j < nums.size(); j++)
		{
			if (nums[i] + nums[j] == target)
			{
				return { i, j };
			}
		}
	}

	return {};
}
} // namespace TwoSum
