#include <unordered_map>
#include <vector>

#include "Solutions.h"

namespace TwoSum
{
std::vector<std::size_t> HashMap::twoSum(const std::vector<int> &nums, const int target) const
{
	std::unordered_map<int, std::size_t> valueToIndexMap;
	valueToIndexMap.reserve(nums.size());

	for (std::size_t i = 0; i < nums.size(); i++)
	{
		int desiredComplement = target - nums[i];
		auto complement = valueToIndexMap.find(desiredComplement);

		if (complement != valueToIndexMap.end())
		{
			return {i, complement->second};
		}
		else
		{
			valueToIndexMap.insert({nums[i], i});
		}
	}

	return {};
}

PreSizedHashMap::PreSizedHashMap(const std::size_t size)
{
	_valueToIndexMap.reserve(size);
}

std::vector<std::size_t> PreSizedHashMap::twoSum(const std::vector<int> &nums, const int target)
{
	_valueToIndexMap.clear();

	for (std::size_t i = 0; i < nums.size(); i++)
	{
		int desiredComplement = target - nums[i];
		auto complement = _valueToIndexMap.find(desiredComplement);

		if (complement != _valueToIndexMap.end())
		{
			return {i, complement->second};
		}
		else
		{
			_valueToIndexMap.insert({nums[i], i});
		}
	}

	return {};
}
} // namespace TwoSum