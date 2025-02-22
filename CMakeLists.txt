cmake_minimum_required(VERSION 3.15)
project(TemperatureMonitor CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Collect all headers from inc/ and source files from src/
include_directories("${CMAKE_CURRENT_SOURCE_DIR}/inc")

file(GLOB SRC_FILES "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")

# Create the executable
add_executable(temp_monitor ${SRC_FILES})

