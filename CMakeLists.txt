cmake_minimum_required(VERSION 3.0)
project(x2z)
set(CMAKE_CXX_STANDARD 98)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
include_directories(${PROJECT_SOURCE_DIR}/src/libx2z)
add_library(libx2z
    ${PROJECT_SOURCE_DIR}/src/libx2z/atom.cc
    ${PROJECT_SOURCE_DIR}/src/libx2z/chem.cc
    ${PROJECT_SOURCE_DIR}/src/libx2z/d3.cc
    ${PROJECT_SOURCE_DIR}/src/libx2z/linpack.cc
    ${PROJECT_SOURCE_DIR}/src/libx2z/math.cc
    ${PROJECT_SOURCE_DIR}/src/libx2z/units.cc)
add_executable(x2z ${PROJECT_SOURCE_DIR}/src/x2z.cc)
target_link_libraries(x2z libx2z)
install(TARGETS x2z DESTINATION bin)
