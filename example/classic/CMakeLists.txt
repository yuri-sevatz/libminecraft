project(mc-classic)

find_package(Boost REQUIRED)

file(GLOB_RECURSE ${PROJECT_NAME}_headers "*.hpp")
file(GLOB_RECURSE ${PROJECT_NAME}_sources "*.cpp")

message("Boost_INCLUDE_DIR")
message(${Boost_INCLUDE_DIR})
include_directories(${Boost_INCLUDE_DIR})

add_executable(${PROJECT_NAME} ${${PROJECT_NAME}_headers} ${${PROJECT_NAME}_sources} )

target_link_libraries(${PROJECT_NAME} minecraft)

install(TARGETS ${PROJECT_NAME}
                RUNTIME DESTINATION bin
                LIBRARY DESTINATION lib
                ARCHIVE DESTINATION lib/static)
