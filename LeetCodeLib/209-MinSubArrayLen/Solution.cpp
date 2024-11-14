#include "Solutions.h"

namespace MinSubArrayLen
{
size_t BruteForce::minSubArrayLen(const int target, const std::vector<int> &nums) const
{
	return nums.size() + target;
}
} // namespace MinSubArrayLen
