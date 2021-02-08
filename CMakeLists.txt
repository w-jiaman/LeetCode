# cmake_minimum_required(VERSION <specify CMake version here>)
project(LeetCode)

set(CMAKE_CXX_STANDARD 14)

add_executable(LeetCode main.cpp Solution.cpp Solution.h)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static-libgcc -static-libstdc++ -Wl,-Bstatic -lstdc++ -lpthread -Wl,-Bdynamic")