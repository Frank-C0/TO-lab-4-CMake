if(EXISTS "/home/runner/TO-lab-4-CMake/build/hello_test[1]_tests.cmake")
  include("/home/runner/TO-lab-4-CMake/build/hello_test[1]_tests.cmake")
else()
  add_test(hello_test_NOT_BUILT hello_test_NOT_BUILT)
endif()
