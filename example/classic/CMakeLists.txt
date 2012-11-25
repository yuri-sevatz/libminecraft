project(mc-classic)

find_package(Boost REQUIRED)

set(${PROJECT_NAME}_command_headers
    command/cuboid.hpp
)

set(${PROJECT_NAME}_command_sources
    command/cuboid.cpp
)

set(${PROJECT_NAME}_headers
    ${${PROJECT_NAME}_command_sources}
    command.hpp
    myclassicclient.hpp
)
set(${PROJECT_NAME}_sources
    ${${PROJECT_NAME}_command_sources}
    main.cpp
    command.cpp
    myclassicclient.cpp
)

message("Boost_INCLUDE_DIR")
message(${Boost_INCLUDE_DIR})
include_directories(${Boost_INCLUDE_DIR})

add_executable(${PROJECT_NAME} ${${PROJECT_NAME}_headers} ${${PROJECT_NAME}_sources} )

target_link_libraries(${PROJECT_NAME} minecraft)

install(TARGETS ${PROJECT_NAME}
                RUNTIME DESTINATION bin
                LIBRARY DESTINATION lib
                ARCHIVE DESTINATION lib/static)
