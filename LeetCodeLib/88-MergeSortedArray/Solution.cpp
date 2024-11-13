#include "Solutions.h"

namespace MergeSortedArray
{
void Solution::merge(std::vector<int> &nums1, int m, std::vector<int> &nums2, int n) const
{
	int totalSize = m + n;

	// Decrement to get index of last elements
	m--;
	n--;

	// Starting at the end of each vector search for where elements should
	// go into `nums1` starting from the end
	for (int i = totalSize - 1; i >= 0 && n >= 0; i--)
	{
		if (m < 0 || nums2[n] > nums1[m])
		{
			nums1[i] = nums2[n--];
		}
		else
		{
			nums1[i] = nums1[m--];
		}
	}
}
} // namespace MergeSortedArray
