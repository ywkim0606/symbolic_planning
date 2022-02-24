# This file should be used as a template for creating new projects with Python
# wrapping using the CMake tools

# ##############################################################################
# To create your own project, replace "wrap_example" with the actual name of
# your project
cmake_minimum_required(VERSION 3.9)
# If you change the project name, you also need to change the folder name of
# `python/wrap_example_py`
project(wrap_example CXX C)
set(CXX_STANDARD 11)

# ##############################################################################
# Set the python version
set(WRAP_PYTHON_VERSION
    "Default"
    CACHE STRING "The Python version to use for wrapping")

# ##############################################################################
# Find the gtwrap package so we have access to the wrapper
find_package(gtwrap)

# ##############################################################################
# Add the local source directory for CMake Ensure that local folder is searched
# before library folders
include_directories(BEFORE "${PROJECT_SOURCE_DIR}")

# ##############################################################################
# Build static library from common sources
add_library(${PROJECT_NAME} SHARED src/greeting.h src/greeting.cpp)
target_link_libraries(${PROJECT_NAME})

# ##############################################################################
# Install library
install(
  TARGETS ${PROJECT_NAME}
  LIBRARY DESTINATION lib
  ARCHIVE DESTINATION lib
  RUNTIME DESTINATION bin)

# ##############################################################################
# Build Pybind wrapper.
# This is our in-house wrapper project which parses an interface file
# to generate the wrapper.
# Installing it follows the standard CMake process.

# CMake flag to wrap this project.
option(WRAP_EXAMPLE_BUILD_PYTHON "Build the Python wrapper" ON)

# Set the version for the project. Needed for setup.py.
set(WRAP_EXAMPLE_VERSION_STRING 1.0.0) # Needed for generating setup.py

if(WRAP_EXAMPLE_BUILD_PYTHON)
  add_subdirectory(python)
endif()

message("========== Configuration Options ==========")
message(STATUS "Project:                  ${PROJECT_NAME}")
message(STATUS "Build Python:             ${WRAP_EXAMPLE_BUILD_PYTHON}")
message(STATUS "Python Version:           ${WRAP_PYTHON_VERSION}")
message("===========================================")
