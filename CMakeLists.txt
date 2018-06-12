project(x2z)
cmake_minimum_required(VERSION 3.0)
find_package(PythonInterp REQUIRED)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)
include_directories(${PROJECT_SOURCE_DIR}/src/libx2z)
add_library(libx2z
    ${PROJECT_SOURCE_DIR}/src/libx2z/atom.cc
    ${PROJECT_SOURCE_DIR}/src/libx2z/chem.cc
    ${PROJECT_SOURCE_DIR}/src/libx2z/d3.cc
    ${PROJECT_SOURCE_DIR}/src/libx2z/linpack.cc
    ${PROJECT_SOURCE_DIR}/src/libx2z/math.cc
    ${PROJECT_SOURCE_DIR}/src/libx2z/units.cc)
add_library(x2ztools SHARED ${PROJECT_SOURCE_DIR}/src/x2ztools.cc)
set_target_properties(x2ztools PROPERTIES PREFIX "")
add_executable(x2z ${PROJECT_SOURCE_DIR}/src/x2z.cc)
target_link_libraries(x2z libx2z)
target_link_libraries(x2ztools libx2z)
install(TARGETS x2z DESTINATION bin)
install(TARGETS x2ztools LIBRARY DESTINATION lib)
