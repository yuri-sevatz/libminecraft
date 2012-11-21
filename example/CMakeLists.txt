project(example)

OPTION(EXAMPLE "Build Examples" OFF)
IF(DEFINED EXAMPLE)
add_subdirectory(classic)
add_subdirectory(mainline)
ENDIF(DEFINED EXAMPLE)
