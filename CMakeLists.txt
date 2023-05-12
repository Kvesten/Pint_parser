cmake_minimum_required(VERSION 3.0)

project(Point_parse)

set(SOURCE_CPP main.cpp MyFunc.cpp)

include_directories(include/point)
include_directories(include/settings)
add_subdirectory(include/point)
add_subdirectory(include/settings)

add_executable(${PROJECT_NAME} ${SOURCE_CPP})

target_link_libraries(${PROJECT_NAME} point)
target_link_libraries(${PROJECT_NAME} settings)

# add_executable(what main.cpp point.cpp MyFunc.cpp)
