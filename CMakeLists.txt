cmake_minimum_required(VERSION 2.8.12)
# Every project needs a name.  We call this the "examples" project.
project(examples)

find_package(dlib REQUIRED)

find_package(Boost)

include_directories(${Boost_INCLUDE_DIR})

add_executable(kkmeans main.cpp)

add_executable(data_generator datagenerator.cpp)

target_link_libraries(kkmeans dlib::dlib)

target_link_libraries(dg dlib::dlib)
