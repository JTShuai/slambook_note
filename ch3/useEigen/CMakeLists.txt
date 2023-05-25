# 声明 cmake 最低版本
cmake_minimum_required (VERSION 2.8)

# 声明一个 cmake 工程
project( UseEigen)

# 添加一个可执行程序
# 语法: add_executable (程序名 源代码文件)
add_executable(eigenMatrix eigenMatrix.cpp )

# 添加头文件
# 因为Eigen 库只有头文件，我们不需要再用tartget_link_libraries 语句将程序链接到库上
include_directories( "/usr/include/eigen3" )