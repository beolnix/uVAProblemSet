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

# main src
# uVA_100
add_executable(uVA_100 src/uVA_100/uVA_100_launcher.cpp)
add_library (uVA_100_lib src/uVA_100/uVA_100.cpp src/uVA_100/uVA_100.hpp)
target_link_libraries(uVA_100 uVA_100_lib)

# uVA_0272
add_executable(uVA_0272 src/uVA_0272/uVA_0272_launcher.cpp)
add_library (uVA_0272_lib src/uVA_0272/uVA_0272.cpp src/uVA_0272/uVA_0272.hpp)
target_link_libraries(uVA_0272 uVA_0272_lib)


# tests
# uVA_100
add_executable(uVA_100_test test/uVA_100/uVA_100_test.cpp)
target_link_libraries(uVA_100_test ${Boost_LIBRARIES} uVA_100_lib)

set_target_properties(uVA_100_test PROPERTIES 
            RUNTIME_OUTPUT_DIRECTORY  ${CMAKE_CURRENT_SOURCE_DIR}/build)

add_test( NAME uVA_100_test 
          WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/build 
          COMMAND ${CMAKE_CURRENT_SOURCE_DIR}/build/uVA_100_test)

# uVA_0272
add_executable(uVA_0272_test test/uVA_0272/uVA_0272_test.cpp)
target_link_libraries(uVA_0272_test ${Boost_LIBRARIES} uVA_0272_lib)

set_target_properties(uVA_0272_test PROPERTIES 
            RUNTIME_OUTPUT_DIRECTORY  ${CMAKE_CURRENT_SOURCE_DIR}/build)

add_test( NAME uVA_0272_test 
          WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/build 
          COMMAND ${CMAKE_CURRENT_SOURCE_DIR}/build/uVA_0272_test)          



