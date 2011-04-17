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

set(${PROJECT_NAME}_headers_core_protocol_classic_client_packet
    core/protocol/classic/client/packet/ident.hpp
    core/protocol/classic/client/packet/message.hpp
    core/protocol/classic/client/packet/posdir.hpp
    core/protocol/classic/client/packet/setblock.hpp
)

set(${PROJECT_NAME}_sources_core_protocol_classic_client_packet
    core/protocol/classic/client/packet/ident.cpp
    core/protocol/classic/client/packet/message.cpp
    core/protocol/classic/client/packet/posdir.cpp
    core/protocol/classic/client/packet/setblock.cpp
)

set(${PROJECT_NAME}_headers_core_protocol_classic_client
    ${${PROJECT_NAME}_headers_core_protocol_classic_client_packet}
    core/protocol/classic/client/packet.hpp
    core/protocol/classic/client/protocol.hpp
)

set(${PROJECT_NAME}_sources_core_protocol_classic_client
    ${${PROJECT_NAME}_sources_core_protocol_classic_client_packet}
    core/protocol/classic/client/protocol.cpp
)

set(${PROJECT_NAME}_headers_core_protocol_classic_server_packet
    core/protocol/classic/server/packet/disconnect.hpp
    core/protocol/classic/server/packet/ident.hpp
    core/protocol/classic/server/packet/levelbegin.hpp
    core/protocol/classic/server/packet/levelchunk.hpp
    core/protocol/classic/server/packet/leveldone.hpp
    core/protocol/classic/server/packet/message.hpp
    core/protocol/classic/server/packet/playerdespawn.hpp
    core/protocol/classic/server/packet/playerdir.hpp
    core/protocol/classic/server/packet/playerop.hpp
    core/protocol/classic/server/packet/playerpos.hpp
    core/protocol/classic/server/packet/playerposdir.hpp
    core/protocol/classic/server/packet/playerspawn.hpp
    core/protocol/classic/server/packet/playerteleport.hpp
    core/protocol/classic/server/packet/ping.hpp
    core/protocol/classic/server/packet/setblock.hpp
)

set(${PROJECT_NAME}_sources_core_protocol_classic_server_packet
    core/protocol/classic/server/packet/disconnect.cpp
    core/protocol/classic/server/packet/ident.cpp
    core/protocol/classic/server/packet/levelbegin.cpp
    core/protocol/classic/server/packet/levelchunk.cpp
    core/protocol/classic/server/packet/leveldone.cpp
    core/protocol/classic/server/packet/message.cpp
    core/protocol/classic/server/packet/playerdespawn.cpp
    core/protocol/classic/server/packet/playerdir.cpp
    core/protocol/classic/server/packet/playerop.cpp
    core/protocol/classic/server/packet/playerpos.cpp
    core/protocol/classic/server/packet/playerposdir.cpp
    core/protocol/classic/server/packet/playerspawn.cpp
    core/protocol/classic/server/packet/playerteleport.cpp
    core/protocol/classic/server/packet/ping.cpp
    core/protocol/classic/server/packet/setblock.cpp
)

set(${PROJECT_NAME}_headers_core_protocol_classic_server
    ${${PROJECT_NAME}_headers_core_protocol_classic_server_packet}
    core/protocol/classic/server/packet.hpp
    core/protocol/classic/server/protocol.hpp
)

set(${PROJECT_NAME}_sources_core_protocol_classic_server
    ${${PROJECT_NAME}_sources_core_protocol_classic_server_packet}
    core/protocol/classic/server/protocol.cpp
)

set(${PROJECT_NAME}_headers_core_protocol_classic
    ${${PROJECT_NAME}_headers_core_protocol_classic_client}
    ${${PROJECT_NAME}_headers_core_protocol_classic_server}
    core/protocol/classic/client.hpp
    core/protocol/classic/mctypes.hpp
    core/protocol/classic/packet.hpp
    core/protocol/classic/protocol.hpp
    core/protocol/classic/stream.hpp
)

set(${PROJECT_NAME}_sources_core_protocol_classic
    ${${PROJECT_NAME}_sources_core_protocol_classic_client}
    ${${PROJECT_NAME}_sources_core_protocol_classic_server}
    core/protocol/classic/client.cpp
    core/protocol/classic/stream.cpp
)

set(${PROJECT_NAME}_headers_core_protocol_mainline_client_packet
    core/protocol/mainline/client/packet/ident.hpp
)

set(${PROJECT_NAME}_sources_core_protocol_mainline_client_packet
    core/protocol/mainline/client/packet/ident.cpp
)

set(${PROJECT_NAME}_headers_core_protocol_mainline_client
    ${${PROJECT_NAME}_headers_core_protocol_mainline_client_packet}
    core/protocol/mainline/client/packet.hpp
    core/protocol/mainline/client/protocol.hpp
)

set(${PROJECT_NAME}_sources_core_protocol_mainline_client
    ${${PROJECT_NAME}_sources_core_protocol_mainline_client_packet}
    core/protocol/mainline/client/protocol.cpp
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
    core/protocol/mainline/client.hpp
    core/protocol/mainline/mctypes.hpp
    core/protocol/mainline/packet.hpp
    core/protocol/mainline/protocol.hpp
    core/protocol/mainline/stream.hpp
)

set(${PROJECT_NAME}_sources_core_protocol_mainline
    ${${PROJECT_NAME}_sources_core_protocol_mainline_client}
    ${${PROJECT_NAME}_sources_core_protocol_mainline_server}
    core/protocol/mainline/client.cpp
    core/protocol/mainline/stream.cpp
)

set(${PROJECT_NAME}_headers_core_protocol
    ${${PROJECT_NAME}_headers_core_protocol_classic}
    ${${PROJECT_NAME}_headers_core_protocol_mainline}
    core/protocol/mctypes.hpp
    core/protocol/packet.hpp
    core/protocol/protocol.hpp
    core/protocol/packet.hpp
    core/protocol/stream.hpp
)

set(${PROJECT_NAME}_sources_core_protocol
    ${${PROJECT_NAME}_sources_core_protocol_classic}
    ${${PROJECT_NAME}_sources_core_protocol_mainline}
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

set(${PROJECT_NAME}_headers_support_io_bigendian
    support/io/bigendian/stream.hpp
)

set(${PROJECT_NAME}_sources_support_io_bigendian
    support/io/bigendian/stream.cpp
)

set(${PROJECT_NAME}_headers_support_io
    ${${PROJECT_NAME}_headers_support_io_bigendian}
    support/io/stream.hpp
)
set(${PROJECT_NAME}_sources_support_io
    ${${PROJECT_NAME}_sources_support_io_bigendian}
)

set(${PROJECT_NAME}_headers_support_java
    support/java/jtypes.hpp
)
set(${PROJECT_NAME}_sources_support_java
    
)

set(${PROJECT_NAME}_headers_support
    ${${PROJECT_NAME}_headers_support_fsm}
    ${${PROJECT_NAME}_headers_support_io}
    ${${PROJECT_NAME}_headers_support_java}
)
set(${PROJECT_NAME}_sources_support
    ${${PROJECT_NAME}_sources_support_fsm}
    ${${PROJECT_NAME}_sources_support_io}
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
