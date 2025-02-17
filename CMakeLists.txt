cmake_minimum_required(VERSION 3.10)
project(MyEmbeddedProject C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

file(GLOB SRC_FILES "${CMAKE_CURRENT_SOURCE_DIR}/src/*.c")
include_directories("${CMAKE_CURRENT_SOURCE_DIR}/include")

add_executable(temp_monitor ${SRC_FILES})

add_definitions(-DUSE_ADC_SIM)

add_definitions(-DCFG_MODE)
