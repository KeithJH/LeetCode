# CMakeList.txt : CMake project for LeetCodeLib

add_library (LeetCodeLib STATIC "1-TwoSum/BruteForce.cpp" "1-TwoSum/Solutions.h" "1-TwoSum/HashMap.cpp" "1-TwoSum/Avx2.cpp" "1-TwoSum/Avx512.cpp"  "2-AddTwoNumbers/Solutions.h" "2-AddTwoNumbers/Iterative.cpp")
target_compile_options(LeetCodeLib PRIVATE ${WARNING_OPTIONS})
target_compile_options(LeetCodeLib PRIVATE ${SANITIZER_OPTIONS})
target_link_options(LeetCodeLib PRIVATE ${SANITIZER_OPTIONS})
