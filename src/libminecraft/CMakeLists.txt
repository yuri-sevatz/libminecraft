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

set(${PROJECT_NAME}_headers_core_classic_net_state
    core/classic/net/state/cliconnecting.hpp
    core/classic/net/state/clidisconnected.hpp
    core/classic/net/state/cligame.hpp
    core/classic/net/state/cliloadingmap.hpp
    core/classic/net/state/clinegotiating.hpp
)
set(${PROJECT_NAME}_sources_core_classic_net_state
    core/classic/net/state/cliconnecting.cpp
    core/classic/net/state/clidisconnected.cpp
    core/classic/net/state/cligame.cpp
    core/classic/net/state/cliloadingmap.cpp
    core/classic/net/state/clinegotiating.cpp
)

set(${PROJECT_NAME}_headers_core_classic_net
    ${${PROJECT_NAME}_headers_core_classic_net_state}
    core/classic/net/clientstatemachine.hpp
    core/classic/net/clistate.hpp
)
set(${PROJECT_NAME}_sources_core_classic_net
    ${${PROJECT_NAME}_sources_core_classic_net_state}
    core/classic/net/clientstatemachine.cpp
)

set(${PROJECT_NAME}_headers_core_classic_protocol_client_packet
    core/classic/protocol/client/packet/ident.hpp
    core/classic/protocol/client/packet/message.hpp
    core/classic/protocol/client/packet/posdir.hpp
    core/classic/protocol/client/packet/setblock.hpp
)
set(${PROJECT_NAME}_sources_core_classic_protocol_client_packet
    core/classic/protocol/client/packet/ident.cpp
    core/classic/protocol/client/packet/message.cpp
    core/classic/protocol/client/packet/posdir.cpp
    core/classic/protocol/client/packet/setblock.cpp
)

set(${PROJECT_NAME}_headers_core_classic_protocol_client
    ${${PROJECT_NAME}_headers_core_classic_protocol_client_packet}
    core/classic/protocol/client/packet.hpp
    core/classic/protocol/client/protocol.hpp
)
set(${PROJECT_NAME}_sources_core_classic_protocol_client
    ${${PROJECT_NAME}_sources_core_classic_protocol_client_packet}
    core/classic/protocol/client/protocol.cpp
)

set(${PROJECT_NAME}_headers_core_classic_protocol_server_packet
    core/classic/protocol/server/packet/disconnect.hpp
    core/classic/protocol/server/packet/ident.hpp
    core/classic/protocol/server/packet/levelbegin.hpp
    core/classic/protocol/server/packet/levelchunk.hpp
    core/classic/protocol/server/packet/leveldone.hpp
    core/classic/protocol/server/packet/message.hpp
    core/classic/protocol/server/packet/playerdespawn.hpp
    core/classic/protocol/server/packet/playerdir.hpp
    core/classic/protocol/server/packet/playerop.hpp
    core/classic/protocol/server/packet/playerpos.hpp
    core/classic/protocol/server/packet/playerposdir.hpp
    core/classic/protocol/server/packet/playerspawn.hpp
    core/classic/protocol/server/packet/playerteleport.hpp
    core/classic/protocol/server/packet/ping.hpp
    core/classic/protocol/server/packet/setblock.hpp
)
set(${PROJECT_NAME}_sources_core_classic_protocol_server_packet
    core/classic/protocol/server/packet/disconnect.cpp
    core/classic/protocol/server/packet/ident.cpp
    core/classic/protocol/server/packet/levelbegin.cpp
    core/classic/protocol/server/packet/levelchunk.cpp
    core/classic/protocol/server/packet/leveldone.cpp
    core/classic/protocol/server/packet/message.cpp
    core/classic/protocol/server/packet/playerdespawn.cpp
    core/classic/protocol/server/packet/playerdir.cpp
    core/classic/protocol/server/packet/playerop.cpp
    core/classic/protocol/server/packet/playerpos.cpp
    core/classic/protocol/server/packet/playerposdir.cpp
    core/classic/protocol/server/packet/playerspawn.cpp
    core/classic/protocol/server/packet/playerteleport.cpp
    core/classic/protocol/server/packet/ping.cpp
    core/classic/protocol/server/packet/setblock.cpp
)

set(${PROJECT_NAME}_headers_core_classic_protocol_server
    ${${PROJECT_NAME}_headers_core_classic_protocol_server_packet}
    core/classic/protocol/server/packet.hpp
    core/classic/protocol/server/protocol.hpp
)
set(${PROJECT_NAME}_sources_core_classic_protocol_server
    ${${PROJECT_NAME}_sources_core_classic_protocol_server_packet}
    core/classic/protocol/server/protocol.cpp
)

set(${PROJECT_NAME}_headers_core_classic_protocol
    ${${PROJECT_NAME}_headers_core_classic_protocol_client}
    ${${PROJECT_NAME}_headers_core_classic_protocol_server}
    core/classic/protocol/client.hpp
    core/classic/protocol/mctypes.hpp
    core/classic/protocol/packet.hpp
    core/classic/protocol/protocol.hpp
    core/classic/protocol/stream.hpp
)
set(${PROJECT_NAME}_sources_core_classic_protocol
    ${${PROJECT_NAME}_sources_core_classic_protocol_client}
    ${${PROJECT_NAME}_sources_core_classic_protocol_server}
    core/classic/protocol/client.cpp
    core/classic/protocol/stream.cpp
)


set(${PROJECT_NAME}_headers_core_classic_world_map
    core/classic/world/map/mapcell.hpp
)
set(${PROJECT_NAME}_sources_core_classic_world_map
    core/classic/world/map/mapcell.cpp
)

set(${PROJECT_NAME}_headers_core_classic_world
    ${${PROJECT_NAME}_headers_core_classic_world_map}
    core/classic/world/map.hpp
    core/classic/world/player.hpp
)
set(${PROJECT_NAME}_sources_core_classic_world
    ${${PROJECT_NAME}_sources_core_classic_world_map}
    core/classic/world/map.cpp
    core/classic/world/player.cpp
)

set(${PROJECT_NAME}_headers_core_classic
    ${${PROJECT_NAME}_headers_core_classic_net}
    ${${PROJECT_NAME}_headers_core_classic_protocol}
    ${${PROJECT_NAME}_headers_core_classic_world}
    core/classic/minecraftworld.hpp
)
set(${PROJECT_NAME}_sources_core_classic
    ${${PROJECT_NAME}_sources_core_classic_net}
    ${${PROJECT_NAME}_sources_core_classic_protocol}
    ${${PROJECT_NAME}_sources_core_classic_world}
    core/classic/minecraftworld.cpp
)

set(${PROJECT_NAME}_headers_core_mainline_protocol_client_packet
    core/mainline/protocol/client/packet/ident.hpp
    core/mainline/protocol/client/packet/login.hpp
    core/mainline/protocol/client/packet/message.hpp
    core/mainline/protocol/client/packet/player.hpp
    core/mainline/protocol/client/packet/use.hpp
)
set(${PROJECT_NAME}_sources_core_mainline_protocol_client_packet
    core/mainline/protocol/client/packet/ident.cpp
    core/mainline/protocol/client/packet/login.cpp
    core/mainline/protocol/client/packet/message.cpp
    core/mainline/protocol/client/packet/player.cpp
    core/mainline/protocol/client/packet/use.cpp
)

set(${PROJECT_NAME}_headers_core_mainline_protocol_client
    ${${PROJECT_NAME}_headers_core_mainline_protocol_client_packet}
    core/mainline/protocol/client/packet.hpp
    core/mainline/protocol/client/protocol.hpp
)
set(${PROJECT_NAME}_sources_core_mainline_protocol_client
    ${${PROJECT_NAME}_sources_core_mainline_protocol_client_packet}
    core/mainline/protocol/client/protocol.cpp
)

set(${PROJECT_NAME}_headers_core_mainline_protocol_packet
   core/mainline/protocol/packet/message.cpp
)
set(${PROJECT_NAME}_sources_core_mainline_protocol_packet
   core/mainline/protocol/packet/message.hpp
)

set(${PROJECT_NAME}_headers_core_mainline_protocol_server_packet
    core/mainline/protocol/server/packet/equipment.hpp
    core/mainline/protocol/server/packet/health.hpp
    core/mainline/protocol/server/packet/ident.hpp
    core/mainline/protocol/server/packet/login.hpp
    core/mainline/protocol/server/packet/message.hpp
    core/mainline/protocol/server/packet/ping.hpp
    core/mainline/protocol/server/packet/spawnpoint.hpp
    core/mainline/protocol/server/packet/time.hpp
)
set(${PROJECT_NAME}_sources_core_mainline_protocol_server_packet
    core/mainline/protocol/server/packet/equipment.cpp
    core/mainline/protocol/server/packet/health.cpp
    core/mainline/protocol/server/packet/ident.cpp
    core/mainline/protocol/server/packet/login.cpp
    core/mainline/protocol/server/packet/message.cpp
    core/mainline/protocol/server/packet/ping.cpp
    core/mainline/protocol/server/packet/spawnpoint.cpp
    core/mainline/protocol/server/packet/time.cpp
)

set(${PROJECT_NAME}_headers_core_mainline_protocol_server
    ${${PROJECT_NAME}_headers_core_mainline_protocol_server_packet}
    core/mainline/protocol/server/packet.hpp
    core/mainline/protocol/server/protocol.hpp
)
set(${PROJECT_NAME}_sources_core_mainline_protocol_server
    ${${PROJECT_NAME}_sources_core_mainline_protocol_server_packet}
    core/mainline/protocol/server/protocol.cpp
)

set(${PROJECT_NAME}_headers_core_mainline_protocol
    ${${PROJECT_NAME}_headers_core_mainline_protocol_client}
    ${${PROJECT_NAME}_headers_core_mainline_protocol_packet}
    ${${PROJECT_NAME}_headers_core_mainline_protocol_server}
    core/mainline/protocol/client.hpp
    core/mainline/protocol/mctypes.hpp
    core/mainline/protocol/packet.hpp
    core/mainline/protocol/protocol.hpp
    core/mainline/protocol/stream.hpp
)
set(${PROJECT_NAME}_sources_core_mainline_protocol
    ${${PROJECT_NAME}_sources_core_mainline_protocol_client}
    ${${PROJECT_NAME}_sources_core_mainline_protocol_packet}
    ${${PROJECT_NAME}_sources_core_mainline_protocol_server}
    core/mainline/protocol/client.cpp
    core/mainline/protocol/stream.cpp
)

set(${PROJECT_NAME}_headers_core_mainline
    ${${PROJECT_NAME}_headers_core_mainline_protocol}
)
set(${PROJECT_NAME}_sources_core_mainline
    ${${PROJECT_NAME}_sources_core_mainline_protocol}
)

set(${PROJECT_NAME}_headers_core_shared_exception
    core/shared/exception/loginexception.hpp
    core/shared/exception/mapexception.hpp
    core/shared/exception/minecraftexception.hpp
    core/shared/exception/networkexception.hpp
    core/shared/exception/protocolexception.hpp
)
set(${PROJECT_NAME}_sources_core_shared_exception
    core/shared/exception/loginexception.cpp
    core/shared/exception/mapexception.cpp
    core/shared/exception/minecraftexception.cpp
    core/shared/exception/networkexception.cpp
    core/shared/exception/protocolexception.cpp
)

set(${PROJECT_NAME}_headers_core_shared_protocol
    core/shared/protocol/mctypes.hpp
    core/shared/protocol/packet.hpp
    core/shared/protocol/protocol.hpp
    core/shared/protocol/packet.hpp
    core/shared/protocol/stream.hpp
)
set(${PROJECT_NAME}_sources_core_shared_protocol

)

set(${PROJECT_NAME}_headers_core_shared
    ${${PROJECT_NAME}_headers_core_shared_exception}
    ${${PROJECT_NAME}_headers_core_shared_protocol}
)
set(${PROJECT_NAME}_sources_core_shared
    ${${PROJECT_NAME}_sources_core_shared_exception}
    ${${PROJECT_NAME}_sources_core_shared_protocol}
)

set(${PROJECT_NAME}_headers_core
    ${${PROJECT_NAME}_headers_core_classic}
    ${${PROJECT_NAME}_headers_core_mainline}
    ${${PROJECT_NAME}_headers_core_shared}
)
set(${PROJECT_NAME}_sources_core
    ${${PROJECT_NAME}_sources_core_classic}
    ${${PROJECT_NAME}_sources_core_mainline}
    ${${PROJECT_NAME}_sources_core_shared}
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
    ${${PROJECT_NAME}_headers_interfaces}
    ${${PROJECT_NAME}_headers_session}    
    ${${PROJECT_NAME}_headers_support}
    ${${PROJECT_NAME}_headers_utils}
)
set (${PROJECT_NAME}_sources
    ${${PROJECT_NAME}_sources_core}
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
