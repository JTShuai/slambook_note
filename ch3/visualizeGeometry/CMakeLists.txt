# 声明 cmake 最低版本
cmake_minimum_required (VERSION 2.8)

# 声明一个 cmake 工程
project( visualizeGeometry)

# 添加一个可执行程序
# 语法: add_executable (程序名 源代码文件)
# add_executable(visualizeGeometry visualizeGeometry.cpp )


# 添加头文件
# 因为Eigen 库只有头文件，我们不需要再用tartget_link_libraries 语句将程序链接到库上
include_directories( "/usr/include/eigen3")


# 添加第三方包
find_package(Pangolin REQUIRED)
include_directories(${Pangolin_INCLUDE_DIRS})


# 添加库文件
# 语法 add_library (程序名 源代码文件)
# add_library( hello libHelloSLAM.cpp )

# 共享库
# add_library(hello_shared SHARED libHelloSLAM.cpp )

# 添加一个可执行程序，该程序使用了共享库
# add_executable( useHello useHello.cpp )
# target_link_libraries( useHello hello_shared )


add_executable(visualizeGeometry visualizeGeometry.cpp )
target_link_libraries( visualizeGeometry ${Pangolin_LIBRARIES} )

