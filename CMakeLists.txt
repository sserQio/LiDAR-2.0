cmake_minimum_required(VERSION 3.7)

project (LiDAR VERSION 2.0)

include_directories(include)

add_library(LidarDriver
    include/LidarDriver.h
    src/LidarDriver.cpp
)

add_executable(LidarDriverTester
    src/LidarDriverTester.cpp
)

target_link_libraries(LidarDriverTester
    LidarDriver
)
