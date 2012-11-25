project(mc-mainline)

file(GLOB_RECURSE ${PROJECT_NAME}_headers "*.hpp")
file(GLOB_RECURSE ${PROJECT_NAME}_sources "*.cpp")

add_executable(${PROJECT_NAME} ${${PROJECT_NAME}_headers} ${${PROJECT_NAME}_sources} )

target_link_libraries(${PROJECT_NAME} minecraft)

install(TARGETS ${PROJECT_NAME}
                RUNTIME DESTINATION bin
                LIBRARY DESTINATION lib
                ARCHIVE DESTINATION lib/static)
