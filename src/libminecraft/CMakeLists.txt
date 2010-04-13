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
find_package(Boost REQUIRED iostreams thread system)
include_directories(${BOOST_INCLUDE_DIRS})

# add your headers and source files here
# ---------------

set(${PROJECT_NAME}_headers_core_client_state
    core/client/state/cliconnecting.hpp
    core/client/state/clidisconnected.hpp
    core/client/state/cligame.hpp
    core/client/state/cliloadingmap.hpp
    core/client/state/clinegotiating.hpp
)
set(${PROJECT_NAME}_sources_core_client_state
    core/client/state/cliconnecting.cpp
    core/client/state/clidisconnected.cpp
    core/client/state/cligame.cpp
    core/client/state/cliloadingmap.cpp
    core/client/state/clinegotiating.cpp
)
set(${PROJECT_NAME}_headers_core_client
    ${${PROJECT_NAME}_headers_core_client_state}
    core/client/clientstatemachine.hpp
    core/client/clistate.hpp
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

set(${PROJECT_NAME}_headers_core_protocol_mainline_client

)

set(${PROJECT_NAME}_sources_core_protocol_mainline_client

)

set(${PROJECT_NAME}_headers_core_protocol_mainline_server_packet
	core/protocol/mainline/server/packet/ping.hpp
)

set(${PROJECT_NAME}_sources_core_protocol_mainline_server_packet
	core/protocol/mainline/server/packet/ping.cpp
)

set(${PROJECT_NAME}_headers_core_protocol_mainline_server
    ${${PROJECT_NAME}_headers_core_protocol_mainline_server_packet}
	core/protocol/mainline/server/packet.hpp
	core/protocol/mainline/server/protocol.hpp
)

set(${PROJECT_NAME}_sources_core_protocol_mainline_server
    ${${PROJECT_NAME}_sources_core_protocol_mainline_server_packet}
	core/protocol/mainline/server/protocol.cpp
)

set(${PROJECT_NAME}_headers_core_protocol_mainline
    ${${PROJECT_NAME}_headers_core_protocol_mainline_client}
    ${${PROJECT_NAME}_headers_core_protocol_mainline_server}
    core/protocol/mainline/packet.hpp
    core/protocol/mainline/protocol.hpp
)

set(${PROJECT_NAME}_sources_core_protocol_mainline
    ${${PROJECT_NAME}_sources_core_protocol_mainline_client}
    ${${PROJECT_NAME}_sources_core_protocol_mainline_server}
    core/protocol/mainline/protocol.cpp
)

set(${PROJECT_NAME}_headers_core_protocol_classic_client
    core/protocol/classic/client/identpkt.hpp
    core/protocol/classic/client/messagepkt.hpp
    core/protocol/classic/client/packet.hpp
    core/protocol/classic/client/posdirpkt.hpp
    core/protocol/classic/client/protocol.hpp
    core/protocol/classic/client/setblockpkt.hpp
)

set(${PROJECT_NAME}_sources_core_protocol_classic_client
    core/protocol/classic/client/identpkt.cpp
    core/protocol/classic/client/messagepkt.cpp
    core/protocol/classic/client/packet.cpp
    core/protocol/classic/client/posdirpkt.cpp
    core/protocol/classic/client/protocol.cpp
    core/protocol/classic/client/setblockpkt.cpp
)

set(${PROJECT_NAME}_headers_core_protocol_classic_server
    core/protocol/classic/server/disconnectpkt.hpp
    core/protocol/classic/server/identpkt.hpp
    core/protocol/classic/server/levelbeginpkt.hpp
    core/protocol/classic/server/levelchunkpkt.hpp
    core/protocol/classic/server/leveldonepkt.hpp
    core/protocol/classic/server/messagepkt.hpp
    core/protocol/classic/server/packet.hpp
    core/protocol/classic/server/playerdespawnpkt.hpp
    core/protocol/classic/server/playerdirpkt.hpp
    core/protocol/classic/server/playeroppkt.hpp
    core/protocol/classic/server/playerpospkt.hpp
    core/protocol/classic/server/playerposdirpkt.hpp
    core/protocol/classic/server/playerspawnpkt.hpp
    core/protocol/classic/server/playerteleportpkt.hpp
    core/protocol/classic/server/pingpkt.hpp
    core/protocol/classic/server/protocol.hpp
    core/protocol/classic/server/setblockpkt.hpp
)

set(${PROJECT_NAME}_sources_core_protocol_classic_server
    core/protocol/classic/server/disconnectpkt.cpp
    core/protocol/classic/server/identpkt.cpp
    core/protocol/classic/server/levelbeginpkt.cpp
    core/protocol/classic/server/levelchunkpkt.cpp
    core/protocol/classic/server/leveldonepkt.cpp
    core/protocol/classic/server/messagepkt.cpp
    core/protocol/classic/server/packet.cpp
    core/protocol/classic/server/playerdespawnpkt.cpp
    core/protocol/classic/server/playerdirpkt.cpp
    core/protocol/classic/server/playeroppkt.cpp
    core/protocol/classic/server/playerpospkt.cpp
    core/protocol/classic/server/playerposdirpkt.cpp
    core/protocol/classic/server/playerspawnpkt.cpp
    core/protocol/classic/server/playerteleportpkt.cpp
    core/protocol/classic/server/pingpkt.cpp
    core/protocol/classic/server/protocol.cpp
    core/protocol/classic/server/setblockpkt.cpp
)

set(${PROJECT_NAME}_headers_core_protocol_classic
    ${${PROJECT_NAME}_headers_core_protocol_classic_client}
    ${${PROJECT_NAME}_headers_core_protocol_classic_server}
    core/protocol/classic/packet.hpp
    core/protocol/classic/protocol.hpp
)

set(${PROJECT_NAME}_sources_core_protocol_classic
    ${${PROJECT_NAME}_sources_core_protocol_classic_client}
    ${${PROJECT_NAME}_sources_core_protocol_classic_server}
    core/protocol/classic/protocol.cpp
)

set(${PROJECT_NAME}_headers_core_protocol
    ${${PROJECT_NAME}_headers_core_protocol_classic}
    ${${PROJECT_NAME}_headers_core_protocol_mainline}
    core/protocol/mctypes.hpp
    core/protocol/protocol.hpp
    core/protocol/packet.hpp
    core/protocol/stream.hpp
)
set(${PROJECT_NAME}_sources_core_protocol
    ${${PROJECT_NAME}_sources_core_protocol_classic}
    ${${PROJECT_NAME}_sources_core_protocol_mainline}
    core/protocol/stream.cpp
)

set(${PROJECT_NAME}_headers_core
    ${${PROJECT_NAME}_headers_core_client}
    ${${PROJECT_NAME}_headers_core_map}
    ${${PROJECT_NAME}_headers_core_player}
    ${${PROJECT_NAME}_headers_core_protocol}
    core/minecraftworld.hpp
)
set(${PROJECT_NAME}_sources_core
    ${${PROJECT_NAME}_sources_core_client}
    ${${PROJECT_NAME}_sources_core_map}
    ${${PROJECT_NAME}_sources_core_player}
    ${${PROJECT_NAME}_sources_core_protocol}
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
    interfaces/clienteventhandler.cpp
)

set(${PROJECT_NAME}_headers_session
    session/minecraftsession.hpp
    session/remotesession.hpp
)

set(${PROJECT_NAME}_sources_session
    session/minecraftsession.cpp
    session/remotesession.cpp
)


set(${PROJECT_NAME}_headers_support_fsm
    support/fsm/abstractstate.hpp
    support/fsm/abstractstatemachine.hpp
    support/fsm/actionstate.hpp
    support/fsm/actionstatemachine.hpp
)
set(${PROJECT_NAME}_sources_support_fsm

)

set(${PROJECT_NAME}_headers_support_java
    support/fsm/java/jtypes.hpp
)
set(${PROJECT_NAME}_sources_support_java
    
)

set(${PROJECT_NAME}_headers_support
    ${${PROJECT_NAME}_headers_support_fsm}
    ${${PROJECT_NAME}_headers_support_java}
)
set(${PROJECT_NAME}_sources_support
    ${${PROJECT_NAME}_sources_support_fsm}
    ${${PROJECT_NAME}_sources_support_java}
)

set(${PROJECT_NAME}_headers_utils
	utils/mcstring.hpp
)
set(${PROJECT_NAME}_sources_utils
	utils/mcstring.cpp
)

set (${PROJECT_NAME}_headers
    ${${PROJECT_NAME}_headers_core}
    ${${PROJECT_NAME}_headers_exceptions}
    ${${PROJECT_NAME}_headers_interfaces}
    ${${PROJECT_NAME}_headers_session}    
    ${${PROJECT_NAME}_headers_support}
    ${${PROJECT_NAME}_headers_utils}
)

set (${PROJECT_NAME}_sources
    ${${PROJECT_NAME}_sources_core}
    ${${PROJECT_NAME}_sources_exceptions}
    ${${PROJECT_NAME}_sources_interfaces}
    ${${PROJECT_NAME}_sources_session}
    ${${PROJECT_NAME}_sources_support}
    ${${PROJECT_NAME}_sources_utils}
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
