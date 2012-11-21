cmake_minimum_required(VERSION 2.8)

# project details
# ---------------
project(minecraft)

set(VERSION_MAJOR "0")
set(VERSION_MINOR "1")
set(VERSION_PATCH "0")
set(VERSION "${VERSION_MAJOR}.${VERSION_MINOR}.${VERSION_PATCH}")

# required dependencies
set(Boost_USE_STATIC_LIBS OFF)
find_package(Boost COMPONENTS iostreams thread system REQUIRED)
#set(QT_USE_QTWEBKIT TRUE)
#find_package(Qt4 REQUIRED)

file(GLOB_RECURSE ${PROJECT_NAME}_pri_headers "libminecraft/*.hpp")
file(GLOB_RECURSE ${PROJECT_NAME}_pri_sources "libminecraft/*.cpp")

file(GLOB_RECURSE ${PROJECT_NAME}_pub_headers "../include/libminecraft/*.hpp")
file(GLOB_RECURSE ${PROJECT_NAME}_pub_sources "../include/libminecraft/*.cpp")

set(${PROJECT_NAME}_headers
    ${${PROJECT_NAME}_pri_headers}
    ${${PROJECT_NAME}_pub_headers}
)

set(${PROJECT_NAME}_sources
    ${${PROJECT_NAME}_pri_sources}
    ${${PROJECT_NAME}_pub_sources}
)

# Includes
# ---------------
message("Boost_INCLUDE_DIR")
message(${Boost_INCLUDE_DIR})
include_directories(${Boost_INCLUDE_DIR})

# Pre-linkage Qt
# ---------------
#INCLUDE(${QT_USE_FILE})

# Linked Libraries
# ---------------
message("Boost_LIBRARY_DIRS")
message(${Boost_LIBRARY_DIRS})
## For MSVS2010 - has issues with target_link_libraries
## Still looking for a way to turn this on pragmatically
#link_directories(${Boost_LIBRARY_DIRS})

# Create the library
# ---------------
add_library(${PROJECT_NAME} SHARED ${${PROJECT_NAME}_headers} ${${PROJECT_NAME}_sources})

target_link_libraries(${PROJECT_NAME} ${Boost_LIBRARIES})

# Install
# ---------------
install(TARGETS ${PROJECT_NAME}
                RUNTIME DESTINATION bin
                LIBRARY DESTINATION lib
                ARCHIVE DESTINATION lib/static)
