cmake_minimum_required(VERSION 2.8)

project(libminecraft)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/bin)

include_directories(include)
#Expose the auto-generated externs from the library available to all targets
#This allows them to still work during the build without installing them first
include_directories(${CMAKE_CURRENT_BINARY_DIR}/src)
add_subdirectory(src)

OPTION(EXAMPLE "Build Examples" ON)
IF(EXAMPLE)
add_subdirectory(example)
ENDIF(EXAMPLE)

OPTION(HEADERS "Install Headers" OFF)
IF(HEADERS)
install(DIRECTORY include DESTINATION include)
#Include auto-generated headers generated at build time
install(DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/src/ DESTINATION include
    FILES_MATCHING PATTERN "*.h" PATTERN "*.hpp"
)
ENDIF(HEADERS)
