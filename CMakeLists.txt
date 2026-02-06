cmake_minimum_required(VERSION 4.2)

project(cpp_testing_grounds)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SOURCE_FILES
    src/main.cpp
    src/modules/memory.cpp
)

add_executable(cpp_testing_grounds ${SOURCE_FILES})
target_include_directories(cpp_testing_grounds PRIVATE include)
