cmake_minimum_required(VERSION 3.0)

project(PROJECT)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")

set(CMAKE_BUILD_TYPE Debug)

include_directories(${CMAKE_SOURSE_DIR}/importantProject/include)

add_executable(my_cmake_exe demo.cpp src/manager.cpp src/mode.cpp src/person.cpp src/seller.cpp src/sellerPerson.cpp src/sellerManager.cpp)