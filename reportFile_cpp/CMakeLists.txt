cmake_minimum_required(VERSION 3.14)

#项目名称
project(DEMO)

#设置debug模式
set(CMAKE_BUILD_TYPE "Debug")

#设置源文件根目录
aux_source_directory(. DIR_ROOT)
aux_source_directory(./src DIR_SRC)

include_directories("./include")

set(CMAKE_CXX_STANDARD 14)

#包含哪些文件
add_executable(demo ${DIR_ROOT} ${DIR_SRC})

#添加一个库
#语法：add_library( 库名称 源代码文件 ），会生成 lib库名称.a（静态库）
#语法：add_library( 库名称 SHARED 源代码文件 ），会生成 lib库名称.so （共享库）
# add_library( hello libHelloSLAM.cpp)

# C++ 的解决办法
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -fexec-charset=GBK")