# @file CMakeLists.txt
# 
# CMake build for rainfall

cmake_minimum_required(VERSION 3.31)

project(Rainfall)

# Rainfall
add_executable(rainfall rainfall.cpp)
target_compile_features(rainfall PRIVATE cxx_std_17)

# Turn on all warnings, and make warnings errors
target_compile_options(rainfall PRIVATE
    $<$<CXX_COMPILER_ID:MSVC>:/W4;/WX>
    $<$<NOT:$<CXX_COMPILER_ID:MSVC>>:-Wall;-Wextra;-pedantic;-Werror>
)

# Run command
add_custom_target(run $<TARGET_FILE:rainfall> < ${CMAKE_SOURCE_DIR}/demo.csv)

# Check command - use diff to check output
find_program(DIFF NAMES diff)
add_custom_target(check
    COMMAND $<TARGET_FILE:rainfall> < ${CMAKE_SOURCE_DIR}/demo.csv | ${DIFF} ${CMAKE_SOURCE_DIR}/demo.txt -
)
