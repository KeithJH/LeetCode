﻿# CMakeList.txt : CMake project for LeetCodeTests

add_executable (LeetCodeTests "1-TwoSumTests.cpp" "2-AddTwoNumbers.cpp" "26-RemoveDuplicates.cpp" "27-RemoveElement.cpp" "80-RemoveDuplicates2.cpp" "88-MergeSortedArray.cpp" "125-ValidPalindrome.cpp" "209-MinSubArrayLen.cpp")
target_link_libraries(LeetCodeTests PRIVATE Catch2::Catch2WithMain)
target_link_libraries(LeetCodeTests PRIVATE LeetCodeLib)
target_compile_options(LeetCodeTests PRIVATE ${WARNING_OPTIONS})
target_compile_options(LeetCodeTests PRIVATE ${SANITIZER_OPTIONS})
target_link_options(LeetCodeTests PRIVATE ${SANITIZER_OPTIONS})

# Register Tests
include(CTest)
include(Catch)
catch_discover_tests(LeetCodeTests)
