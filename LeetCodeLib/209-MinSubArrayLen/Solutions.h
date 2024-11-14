#pragma once
#include <vector>

namespace MinSubArrayLen
{
class BruteForce
{
  public:
	size_t minSubArrayLen(const int target, const std::vector<int> &nums) const;
};
} // namespace MinSubArrayLen