cmake_minimum_required( VERSION 3.7.0 )
# Set the project name and version
project(main VERSION 1.0)
# Specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
# Define a variable with syntax: set(<variable> <value>)
# To use the defined variable: ${variable}
set(SRC_DIR "${CMAKE_CURRENT_SOURCE_DIR}")
# Generate a list of files with syntax: file(GLOB <variable> <files>)
# Specify the sources of the project with ${SRC_DIR}
file(GLOB SOURCES
"${SRC_DIR}/*.h"
"${SRC_DIR}/*.c"
)
# Add the executable with the sources in ${SOURCES}
add_executable(${PROJECT_NAME} ${SOURCES})