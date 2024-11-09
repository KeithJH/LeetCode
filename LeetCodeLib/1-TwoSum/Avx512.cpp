#include <immintrin.h>

#include "Solutions.h"

namespace TwoSum
{
std::vector<std::size_t> Avx512::twoSum(const std::vector<int> &nums, const int target) const
{
	constexpr int LANES = 512 / 8 / sizeof(int);

	// Broadcast the target to a SIMD register
	const __m512i targetElement = _mm512_set1_epi32(target);

	// Keep it easy, if there are less elements than fit in a SIMD register just
	// fall back to the Brute Force solution.
	if (nums.size() >= LANES)
	{
		for (std::size_t i = 0; i < nums.size(); i++)
		{
			// Broadcast the outer loop value to a SIMD register
			const int currentValue = nums[i];
			const __m512i currentElements = _mm512_set1_epi32(currentValue);

			// Compare the sum of the outer value and multiple inner values to the target
			// moving the inner values read by a stride matching the width of the SIMD
			// register
			std::size_t j;
			for (j = i + 1; j + LANES <= nums.size(); j += LANES)
			{
				__m512i nextElements = _mm512_loadu_si512(reinterpret_cast<const __m512i *>(&nums[j]));

				auto sum = _mm512_add_epi32(currentElements, nextElements);
				auto eq = _mm512_cmpeq_epi32_mask(sum, targetElement);

				if (eq)
				{
					std::size_t zeros = _tzcnt_u32(eq);
					std::size_t x = j + zeros;
					return {i, x};
				}
			}

			// Special handling for the tail, where we re-read some values to keep inbounds of the data
			if (j < nums.size())
			{
				j = nums.size() - LANES;

				__m512i nextElements = _mm512_loadu_si512(reinterpret_cast<const __m512i *>(&nums[j]));

				auto sum = _mm512_add_epi32(currentElements, nextElements);
				auto eqMask = _mm512_cmpeq_epi32_mask(sum, targetElement);

				// There are some cases where this chunk of data contains both `i` and `j`, requiring
				// more care to ensure we don't find a solution using a single data element twice
				int indexDiff = static_cast<int>(i - j);
				if (indexDiff >= 0)
				{
					eqMask &= ~(0x1 << indexDiff);
				}

				if (eqMask)
				{
					auto zeros = _tzcnt_u32(eqMask);
					std::size_t x = j + zeros;
					return {i, x};
				}
			}
		}
	}

	BruteForce bruteForceSolver;
	return bruteForceSolver.twoSum(nums, target);
}
}
