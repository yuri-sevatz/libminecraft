cmake_minimum_required(VERSION 2.8)

# project details
# ---------------
project(minecraft)

set(VERSION_MAJOR "0")
set(VERSION_MINOR "1")
set(VERSION_PATCH "0")
set(VERSION "${VERSION_MAJOR}.${VERSION_MINOR}.${VERSION_PATCH}")

# required dependencies
set(Boost_USE_STATIC_LIBS ON)
find_package(Boost REQUIRED system)
include_directories(${BOOST_INCLUDE_DIRS}) 

# add your headers and source files here
# ---------------

set(${PROJECT_NAME}_headers_core_client_state
    core/client/state/cliconnecting.hpp
    core/client/state/clidisconnected.hpp
    core/client/state/cliloadingmap.hpp
    core/client/state/clinegotiating.hpp
    core/client/state/clistate.hpp
)
set(${PROJECT_NAME}_sources_core_client_state
    core/client/state/cliconnecting.cpp
    core/client/state/clidisconnected.cpp
    core/client/state/cliloadingmap.cpp
    core/client/state/clinegotiating.cpp
)
set(${PROJECT_NAME}_headers_core_client
    ${${PROJECT_NAME}_headers_core_client_state}
    core/client/clientstatemachine.hpp
)
set(${PROJECT_NAME}_sources_core_client
    ${${PROJECT_NAME}_sources_core_client_state}
    core/client/clientstatemachine.cpp
)

set(${PROJECT_NAME}_headers_core_map
    core/map/map.hpp
    core/map/mapcell.hpp
)
set(${PROJECT_NAME}_sources_core_map
    core/map/map.cpp
    core/map/mapcell.cpp
)
set(${PROJECT_NAME}_headers_core_player
    core/player/player.hpp
)
set(${PROJECT_NAME}_sources_core_player
    core/player/player.cpp
)

set(${PROJECT_NAME}_headers_core_protocol_client
    core/protocol/client/clientidentpkt.hpp
    core/protocol/client/clientpkt.hpp
)
set(${PROJECT_NAME}_sources_core_protocol_client
    core/protocol/client/clientidentpkt.cpp
    core/protocol/client/clientpkt.cpp
)
set(${PROJECT_NAME}_headers_core_protocol_server
    core/protocol/server/serveridentpkt.hpp
    core/protocol/server/serverlevelbeginpkt.hpp
    core/protocol/server/serverlevelchunkpkt.hpp
    core/protocol/server/serverleveldonepkt.hpp
    core/protocol/server/serverpingpkt.hpp
    core/protocol/server/serverpkt.hpp
)
set(${PROJECT_NAME}_sources_core_protocol_server
    core/protocol/server/serveridentpkt.cpp
    core/protocol/server/serverlevelbeginpkt.cpp
    core/protocol/server/serverlevelchunkpkt.cpp
    core/protocol/server/serverleveldonepkt.cpp
    core/protocol/server/serverpingpkt.cpp
    core/protocol/server/serverpkt.cpp
)

set(${PROJECT_NAME}_headers_core_protocol
    ${${PROJECT_NAME}_headers_core_protocol_client}
    ${${PROJECT_NAME}_headers_core_protocol_server}
    core/protocol/baseprotocol.hpp
    core/protocol/clientprotocol.hpp
    core/protocol/minecraftpacket.hpp
    core/protocol/minecraftstring.hpp
    core/protocol/serverprotocol.hpp
)
set(${PROJECT_NAME}_sources_core_protocol
    ${${PROJECT_NAME}_sources_core_protocol_client}
    ${${PROJECT_NAME}_sources_core_protocol_server}
    core/protocol/baseprotocol.cpp
    core/protocol/clientprotocol.cpp
    core/protocol/minecraftstring.cpp
    core/protocol/serverprotocol.cpp
)

set(${PROJECT_NAME}_headers_core
    ${${PROJECT_NAME}_headers_core_client}
    ${${PROJECT_NAME}_headers_core_map}
    ${${PROJECT_NAME}_headers_core_player}
    ${${PROJECT_NAME}_headers_core_protocol}
    core/minecraftsession.hpp
    core/minecraftworld.hpp
)
set(${PROJECT_NAME}_sources_core
    ${${PROJECT_NAME}_sources_core_client}
    ${${PROJECT_NAME}_sources_core_map}
    ${${PROJECT_NAME}_sources_core_player}
    ${${PROJECT_NAME}_sources_core_protocol}
    core/minecraftsession.cpp
    core/minecraftworld.cpp
)

set(${PROJECT_NAME}_headers_exceptions
    exceptions/loginexception.hpp
    exceptions/mapexception.hpp
    exceptions/minecraftexception.hpp
    exceptions/networkexception.hpp
    exceptions/protocolexception.hpp
)

set(${PROJECT_NAME}_sources_exceptions
    exceptions/loginexception.cpp
    exceptions/mapexception.cpp
    exceptions/minecraftexception.cpp
    exceptions/networkexception.cpp
    exceptions/protocolexception.cpp
)

set(${PROJECT_NAME}_headers_interfaces
    interfaces/clienteventhandler.hpp
)

set(${PROJECT_NAME}_sources_interfaces

)

set(${PROJECT_NAME}_headers_support_fsm
    support/fsm/abstractstate.hpp
    support/fsm/abstractstatemachine.hpp
    support/fsm/actionstate.hpp
    support/fsm/actionstatemachine.hpp
)
set(${PROJECT_NAME}_sources_support_fsm

)
set(${PROJECT_NAME}_headers_support
    ${${PROJECT_NAME}_headers_support_fsm}
)
set(${PROJECT_NAME}_sources_support
    ${${PROJECT_NAME}_sources_support_fsm}
)



set (${PROJECT_NAME}_headers
    ${${PROJECT_NAME}_headers_core}
    ${${PROJECT_NAME}_headers_exceptions}
    ${${PROJECT_NAME}_headers_interfaces}
    ${${PROJECT_NAME}_headers_support}
    libminecraft.hpp
)

set (${PROJECT_NAME}_sources
    ${${PROJECT_NAME}_sources_core}
    ${${PROJECT_NAME}_sources_exceptions}
    ${${PROJECT_NAME}_sources_interfaces}
    ${${PROJECT_NAME}_sources_support}
)


# Create the library
# ---------------
add_library(${PROJECT_NAME} SHARED ${${PROJECT_NAME}_headers} ${${PROJECT_NAME}_sources})

# linker
# ---------------
target_link_libraries(${PROJECT_NAME} ${Boost_LIBRARIES} )

# install
# ---------------
install(TARGETS ${PROJECT_NAME}
                RUNTIME DESTINATION bin
                LIBRARY DESTINATION lib
                ARCHIVE DESTINATION lib/static)
