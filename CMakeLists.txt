cmake_minimum_required(VERSION 2.8)

project(root)

include_directories(include)

add_subdirectory(src)
add_subdirectory(example)

OPTION(HEADERS "Install Headers" OFF)
IF(DEFINED HEADERS)
install(DIRECTORY include DESTINATION include)
ENDIF(DEFINED HEADERS)
