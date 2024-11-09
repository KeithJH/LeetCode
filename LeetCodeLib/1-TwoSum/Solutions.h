#pragma once
#include <vector>
#include <unordered_map>

namespace TwoSum
{
class BruteForce
{
  public:
	std::vector<std::size_t> twoSum(const std::vector<int> &nums, const int target) const;
};

class HashMap
{
  public:
	std::vector<std::size_t> twoSum(const std::vector<int> &nums, const int target) const;
};

class PreSizedHashMap
{
  public:
	PreSizedHashMap(const std::size_t size = 0);
	std::vector<std::size_t> twoSum(const std::vector<int> &nums, const int target);

  private:
	std::unordered_map<int, std::size_t> _valueToIndexMap;
};

class Avx2
{
  public:
	std::vector<std::size_t> twoSum(const std::vector<int> &nums, const int target) const;
};

class Avx512
{
  public:
	std::vector<std::size_t> twoSum(const std::vector<int> &nums, const int target) const;
};
} // namespace TwoSum