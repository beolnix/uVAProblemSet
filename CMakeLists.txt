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

# uVA_10550 - main
add_executable(uVA_10550 src/uVA_10550/uVA_10550_launcher.cpp)
add_library (uVA_10550_lib src/uVA_10550/uVA_10550.cpp src/uVA_10550/uVA_10550.hpp)
target_link_libraries(uVA_10550 uVA_10550_lib)

# uVA_10550 - test
add_executable(uVA_10550_test test/uVA_10550/uVA_10550_test.cpp)
target_link_libraries(uVA_10550_test ${Boost_LIBRARIES} uVA_10550_lib)

set_target_properties(uVA_10550_test PROPERTIES 
            RUNTIME_OUTPUT_DIRECTORY  ${CMAKE_CURRENT_SOURCE_DIR}/build)

add_test( NAME uVA_10550_test 
          WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/build 
          COMMAND ${CMAKE_CURRENT_SOURCE_DIR}/build/uVA_10550_test)

# uVA_11172 - main
add_executable(uVA_11172 src/uVA_11172/uVA_11172_launcher.cpp)

# uVA_11044 - main
add_executable(uVA_11044 src/uVA_11044/uVA_11044_launcher.cpp)
add_library (uVA_11044_lib src/uVA_11044/uVA_11044.cpp src/uVA_11044/uVA_11044.hpp)
target_link_libraries(uVA_11044 uVA_11044_lib)

# uVA_11044 - test
add_executable(uVA_11044_test test/uVA_11044/uVA_11044_test.cpp)
target_link_libraries(uVA_11044_test ${Boost_LIBRARIES} uVA_11044_lib)

set_target_properties(uVA_11044_test PROPERTIES 
            RUNTIME_OUTPUT_DIRECTORY  ${CMAKE_CURRENT_SOURCE_DIR}/build)

add_test( NAME uVA_11044_test 
          WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/build 
          COMMAND ${CMAKE_CURRENT_SOURCE_DIR}/build/uVA_11044_test)

# uVA_11044 - main
add_executable(uVA_11364 src/uVA_11364/uVA_11364_launcher.cpp)
add_library (uVA_11364_lib src/uVA_11364/uVA_11364.cpp src/uVA_11364/uVA_11364.hpp)
target_link_libraries(uVA_11364 uVA_11364_lib)

# uVA_11044 - test
add_executable(uVA_11364_test test/uVA_11364/uVA_11364_test.cpp)
target_link_libraries(uVA_11364_test ${Boost_LIBRARIES} uVA_11364_lib)

set_target_properties(uVA_11364_test PROPERTIES 
            RUNTIME_OUTPUT_DIRECTORY  ${CMAKE_CURRENT_SOURCE_DIR}/build)

add_test( NAME uVA_11364_test 
          WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/build 
          COMMAND ${CMAKE_CURRENT_SOURCE_DIR}/build/uVA_11364_test)          



