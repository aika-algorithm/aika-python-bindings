cmake_minimum_required(VERSION 3.12)

set(CMAKE_CXX_COMPILER "/usr/bin/c++")
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3 -Wall -std=c++11 -fPIC")
set(CMAKE_LD_FLAGS "${CMAKE_LD_FLAGS} -shared -undefined dynamic_lookup")

project(aika_bindings)

# Find pybind11
find_package(pybind11 REQUIRED)

# Define the C++ extension module
pybind11_add_module(aika_bindings aika-bindings.cpp)

# Find Python and link it
find_package(Python3 REQUIRED COMPONENTS Development)
add_definitions(-DPYBIND11_DEBUG)

include_directories( "../../../target" )

target_link_libraries(example PRIVATE Python3::Python)
#target_link_libraries(aika_bindings PRIVATE ${CMAKE_BINARY_DIR}/libaika.dylib)

message(STATUS "Python include dirs: ${Python3_INCLUDE_DIRS}")
message(STATUS "PyBind11 include dirs: ${pybind11_INCLUDE_DIRS}")