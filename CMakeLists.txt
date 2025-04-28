cmake_minimum_required(VERSION 3.10)
set (CMAKE_CXX_STANDARD 17)
set (CMAKE_CXX_STANDARD_REQUIRED ON)

project(CpuManager)

file(GLOB SOURCES "./src/*.cpp")



add_executable(CpuManager ${SOURCES})


target_include_directories(CpuManager PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/src
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)