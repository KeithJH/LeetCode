# CMakeList.txt : CMake project for LeetCodeLib

add_library (LeetCodeLib STATIC
	"1-TwoSum/BruteForce.cpp" "1-TwoSum/Solutions.h" "1-TwoSum/HashMap.cpp" "1-TwoSum/Avx2.cpp" "1-TwoSum/Avx512.cpp"
	"2-AddTwoNumbers/Solutions.h" "2-AddTwoNumbers/Iterative.cpp" "2-AddTwoNumbers/Recursive.cpp" "2-AddTwoNumbers/CleanIterative.cpp"
	"26-RemoveDuplicates/Solution.cpp" "26-RemoveDuplicates/Solutions.h"
	"27-RemoveElement/Fill.cpp" "27-RemoveElement/Swap.cpp" "27-RemoveElement/Solutions.h"
	"80-RemoveDuplicates2/Solution.cpp" "80-RemoveDuplicates2/Solutions.h"
	"88-MergeSortedArray/Solution.cpp" "88-MergeSortedArray/Solutions.h"
	"125-ValidPalindrome/Solution.cpp" "125-ValidPalindrome/Solutions.h"
	"209-MinSubArrayLen/BruteForce.cpp" "209-MinSubArrayLen/Solutions.h"
)
target_compile_options(LeetCodeLib PRIVATE ${WARNING_OPTIONS})
target_compile_options(LeetCodeLib PRIVATE ${SANITIZER_OPTIONS})
target_link_options(LeetCodeLib PRIVATE ${SANITIZER_OPTIONS})
