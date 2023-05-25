# 声明 cmake 最低版本
cmake_minimum_required (VERSION 2.8)

# 声明一个 cmake 工程
project( exercisech3)

# 添加头文件
include_directories( "/usr/include/eigen3")
include_directories( SYSTEM ${CMAKE_CURRENT_SOURCE_DIR})

# 共享库
add_library(task1 SHARED task1.cpp )

# 添加一个可执行程序，该程序使用了共享库
add_executable( run run.cpp )
target_link_libraries( run task1 )

