cmake_minimum_required(VERSION 3.12)
project(aika_bindings)

# Find pybind11
find_package(pybind11 REQUIRED)

# Define the C++ extension module
pybind11_add_module(aika_bindings aika-bindings.cpp)

# Find Python and link it
find_package(Python3 REQUIRED COMPONENTS Interpreter Development)
add_definitions(-DPYBIND11_DEBUG)

include_directories( "../../../target" )

target_link_libraries(aika_bindings PRIVATE Python3::Python)
target_link_libraries(aika_bindings PRIVATE ${CMAKE_BINARY_DIR}/libaika.dylib)
