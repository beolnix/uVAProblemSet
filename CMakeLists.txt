cmake_minimum_required(VERSION 3.0)
project(uVAProblemSet)

# project version
set(VERSION_MAJOR 1)
set(VERSION_MINOR 0)
set(VERSION_PATCH 0)

enable_testing()

#Prep ourselves for compiling boost
find_package(Boost COMPONENTS unit_test_framework REQUIRED)
include_directories (${Boost_INCLUDE_DIRS})

# uVA_0100 - main
add_executable(uVA_0100 src/uVA_0100/uVA_0100_launcher.cpp)
add_library (uVA_0100_lib src/uVA_0100/uVA_0100.cpp src/uVA_0100/uVA_0100.hpp)
target_link_libraries(uVA_0100 uVA_0100_lib)

# uVA_100 - test
add_executable(uVA_0100_test test/uVA_0100/uVA_0100_test.cpp)
target_link_libraries(uVA_0100_test ${Boost_LIBRARIES} uVA_0100_lib)

set_target_properties(uVA_0100_test PROPERTIES 
            RUNTIME_OUTPUT_DIRECTORY  ${CMAKE_CURRENT_SOURCE_DIR}/build)

add_test( NAME uVA_0100_test 
          WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/build 
          COMMAND ${CMAKE_CURRENT_SOURCE_DIR}/build/uVA_0100_test)

# uVA_0272 - main
add_executable(uVA_0272 src/uVA_0272/uVA_0272_launcher.cpp)
add_library (uVA_0272_lib src/uVA_0272/uVA_0272.cpp src/uVA_0272/uVA_0272.hpp)
target_link_libraries(uVA_0272 uVA_0272_lib)

# uVA_0272 - test
add_executable(uVA_0272_test test/uVA_0272/uVA_0272_test.cpp)
target_link_libraries(uVA_0272_test ${Boost_LIBRARIES} uVA_0272_lib)

set_target_properties(uVA_0272_test PROPERTIES 
            RUNTIME_OUTPUT_DIRECTORY  ${CMAKE_CURRENT_SOURCE_DIR}/build)

add_test( NAME uVA_0272_test 
          WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/build 
          COMMAND ${CMAKE_CURRENT_SOURCE_DIR}/build/uVA_0272_test)      

# uVA_1124 - main
add_executable(uVA_1124 src/uVA_1124/uVA_1124_launcher.cpp)
               



