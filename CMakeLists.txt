cmake_minimum_required(VERSION 3.10)
project(cellularAutomata VERSION 0.1.0)

# include(CTest)
# enable_testing()
SET (CMAKE_CXX_COMPILER "/usr/bin/clang++")
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

INCLUDE(FindPkgConfig)

add_executable(${PROJECT_NAME}
    src/main.cpp
    src/CellularAutomaton.cpp
)

target_link_libraries(${PROJECT_NAME})
target_include_directories(cellularAutomata PUBLIC "${PROJECT_SOURCE_DIR}")

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
