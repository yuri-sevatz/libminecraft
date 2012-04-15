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
set(QT_USE_QTWEBKIT TRUE)
find_package(Qt4 REQUIRED)

# add your headers and source files here
# ---------------

set(${PROJECT_NAME}_headers_classic_session_remote_state
    classic/session/remote/state/connecting.hpp
    classic/session/remote/state/ingame.hpp
    classic/session/remote/state/loadingmap.hpp
    classic/session/remote/state/negotiating.hpp
)
set(${PROJECT_NAME}_sources_classic_session_remote_state
    classic/session/remote/state/connecting.cpp
    classic/session/remote/state/ingame.cpp
    classic/session/remote/state/loadingmap.cpp
    classic/session/remote/state/negotiating.cpp
)

set(${PROJECT_NAME}_headers_classic_session_remote
    ${${PROJECT_NAME}_headers_classic_session_remote_state}
    classic/session/remote/connection.hpp
    classic/session/remote/state.hpp
)
set(${PROJECT_NAME}_sources_classic_session_remote
    ${${PROJECT_NAME}_sources_classic_session_remote_state}
    classic/session/remote/connection.cpp
)

set(${PROJECT_NAME}_headers_classic_session
    ${${PROJECT_NAME}_headers_classic_session_remote}
    classic/session/info.hpp
    classic/session/remote.hpp
)

set(${PROJECT_NAME}_sources_classic_session
    ${${PROJECT_NAME}_sources_classic_session_remote}
    classic/session/info.cpp
    classic/session/remote.cpp
)

set(${PROJECT_NAME}_headers_classic_protocol_client_packet
    classic/protocol/client/packet/ident.hpp
    classic/protocol/client/packet/message.hpp
    classic/protocol/client/packet/posdir.hpp
    classic/protocol/client/packet/setblock.hpp
)
set(${PROJECT_NAME}_sources_classic_protocol_client_packet
    classic/protocol/client/packet/ident.cpp
    classic/protocol/client/packet/message.cpp
    classic/protocol/client/packet/posdir.cpp
    classic/protocol/client/packet/setblock.cpp
)

set(${PROJECT_NAME}_headers_classic_protocol_client
    ${${PROJECT_NAME}_headers_classic_protocol_client_packet}
    classic/protocol/client/packet.hpp
    classic/protocol/client/protocol.hpp
)
set(${PROJECT_NAME}_sources_classic_protocol_client
    ${${PROJECT_NAME}_sources_classic_protocol_client_packet}
    classic/protocol/client/protocol.cpp
)

set(${PROJECT_NAME}_headers_classic_protocol_server_packet
    classic/protocol/server/packet/disconnect.hpp
    classic/protocol/server/packet/ident.hpp
    classic/protocol/server/packet/levelbegin.hpp
    classic/protocol/server/packet/levelchunk.hpp
    classic/protocol/server/packet/leveldone.hpp
    classic/protocol/server/packet/message.hpp
    classic/protocol/server/packet/playerdespawn.hpp
    classic/protocol/server/packet/playerdir.hpp
    classic/protocol/server/packet/playerop.hpp
    classic/protocol/server/packet/playerpos.hpp
    classic/protocol/server/packet/playerposdir.hpp
    classic/protocol/server/packet/playerspawn.hpp
    classic/protocol/server/packet/playerteleport.hpp
    classic/protocol/server/packet/ping.hpp
    classic/protocol/server/packet/setblock.hpp
)
set(${PROJECT_NAME}_sources_classic_protocol_server_packet
    classic/protocol/server/packet/disconnect.cpp
    classic/protocol/server/packet/ident.cpp
    classic/protocol/server/packet/levelbegin.cpp
    classic/protocol/server/packet/levelchunk.cpp
    classic/protocol/server/packet/leveldone.cpp
    classic/protocol/server/packet/message.cpp
    classic/protocol/server/packet/playerdespawn.cpp
    classic/protocol/server/packet/playerdir.cpp
    classic/protocol/server/packet/playerop.cpp
    classic/protocol/server/packet/playerpos.cpp
    classic/protocol/server/packet/playerposdir.cpp
    classic/protocol/server/packet/playerspawn.cpp
    classic/protocol/server/packet/playerteleport.cpp
    classic/protocol/server/packet/ping.cpp
    classic/protocol/server/packet/setblock.cpp
)

set(${PROJECT_NAME}_headers_classic_protocol_server
    ${${PROJECT_NAME}_headers_classic_protocol_server_packet}
    classic/protocol/server/packet.hpp
    classic/protocol/server/protocol.hpp
)
set(${PROJECT_NAME}_sources_classic_protocol_server
    ${${PROJECT_NAME}_sources_classic_protocol_server_packet}
    classic/protocol/server/protocol.cpp
)

set(${PROJECT_NAME}_headers_classic_protocol
    ${${PROJECT_NAME}_headers_classic_protocol_client}
    ${${PROJECT_NAME}_headers_classic_protocol_server}
    classic/protocol/client.hpp
    classic/protocol/packet.hpp
    classic/protocol/protocol.hpp
    classic/protocol/stream.hpp
)
set(${PROJECT_NAME}_sources_classic_protocol
    ${${PROJECT_NAME}_sources_classic_protocol_client}
    ${${PROJECT_NAME}_sources_classic_protocol_server}
    classic/protocol/client.cpp
    classic/protocol/stream.cpp
)


set(${PROJECT_NAME}_headers_classic_game_map
    classic/game/map/block.hpp
    classic/game/map/cell.hpp
    classic/game/map/point.hpp
)
set(${PROJECT_NAME}_sources_classic_game_map
    classic/game/map/block.cpp
    classic/game/map/cell.cpp
    classic/game/map/point.cpp
)

set(${PROJECT_NAME}_headers_classic_game_player
    classic/game/player/local.hpp
)
set(${PROJECT_NAME}_sources_classic_game_player
    classic/game/player/local.cpp
)

set(${PROJECT_NAME}_headers_classic_game
    ${${PROJECT_NAME}_headers_classic_game_map}
    ${${PROJECT_NAME}_headers_classic_game_player}
    classic/game/base.hpp
    classic/game/map.hpp
    classic/game/player.hpp
    classic/game/world.hpp
)
set(${PROJECT_NAME}_sources_classic_game
    ${${PROJECT_NAME}_sources_classic_game_map}
    ${${PROJECT_NAME}_sources_classic_game_player}
    classic/game/map.cpp
    classic/game/player.cpp
    classic/game/world.cpp
)

set(${PROJECT_NAME}_headers_classic
    ${${PROJECT_NAME}_headers_classic_game}
    ${${PROJECT_NAME}_headers_classic_protocol}
    ${${PROJECT_NAME}_headers_classic_session}
    classic/client.hpp
    classic/mctypes.hpp
    classic/session.hpp
)
set(${PROJECT_NAME}_sources_classic
    ${${PROJECT_NAME}_sources_classic_game}
    ${${PROJECT_NAME}_sources_classic_protocol}
    ${${PROJECT_NAME}_sources_classic_session}
    classic/client.cpp
    classic/session.cpp
)


set(${PROJECT_NAME}_headers_mainline_game
    mainline/game/base.hpp
    mainline/game/player.hpp
)

set(${PROJECT_NAME}_sources_mainline_game
    mainline/game/player.cpp
)

set(${PROJECT_NAME}_headers_mainline_protocol_client_packet
    mainline/protocol/client/packet/ident.hpp
    mainline/protocol/client/packet/login.hpp
    mainline/protocol/client/packet/message.hpp
    mainline/protocol/client/packet/player.hpp
    mainline/protocol/client/packet/use.hpp
)
set(${PROJECT_NAME}_sources_mainline_protocol_client_packet
    mainline/protocol/client/packet/ident.cpp
    mainline/protocol/client/packet/login.cpp
    mainline/protocol/client/packet/message.cpp
    mainline/protocol/client/packet/player.cpp
    mainline/protocol/client/packet/use.cpp
)

set(${PROJECT_NAME}_headers_mainline_protocol_client
    ${${PROJECT_NAME}_headers_mainline_protocol_client_packet}
    mainline/protocol/client/packet.hpp
    mainline/protocol/client/protocol.hpp
)
set(${PROJECT_NAME}_sources_mainline_protocol_client
    ${${PROJECT_NAME}_sources_mainline_protocol_client_packet}
    mainline/protocol/client/protocol.cpp
)

set(${PROJECT_NAME}_headers_mainline_protocol_packet
    mainline/protocol/packet/login.hpp
    mainline/protocol/packet/message.cpp
    mainline/protocol/packet/playerposdir.cpp
)
set(${PROJECT_NAME}_sources_mainline_protocol_packet
    mainline/protocol/packet/login.cpp
    mainline/protocol/packet/message.hpp
    mainline/protocol/packet/playerposdir.hpp
)

set(${PROJECT_NAME}_headers_mainline_protocol_server_packet
    mainline/protocol/server/packet/abilities.hpp
    mainline/protocol/server/packet/entityvelocity.hpp
    mainline/protocol/server/packet/equipment.hpp
    mainline/protocol/server/packet/gamestate.hpp
    mainline/protocol/server/packet/health.hpp
    mainline/protocol/server/packet/ident.hpp
    mainline/protocol/server/packet/itemspawn.hpp
    mainline/protocol/server/packet/login.hpp
    mainline/protocol/server/packet/message.hpp
    mainline/protocol/server/packet/mobspawn.hpp
    mainline/protocol/server/packet/movingobjectspawn.hpp
    mainline/protocol/server/packet/ping.hpp
    mainline/protocol/server/packet/playerlistitem.hpp
    mainline/protocol/server/packet/playerposdir.hpp
    mainline/protocol/server/packet/prechunk.hpp
    mainline/protocol/server/packet/spawnpoint.hpp
    mainline/protocol/server/packet/time.hpp
    mainline/protocol/server/packet/windowitems.hpp
)
set(${PROJECT_NAME}_sources_mainline_protocol_server_packet
    mainline/protocol/server/packet/abilities.cpp
    mainline/protocol/server/packet/entityvelocity.cpp
    mainline/protocol/server/packet/equipment.cpp
    mainline/protocol/server/packet/gamestate.cpp
    mainline/protocol/server/packet/health.cpp
    mainline/protocol/server/packet/ident.cpp
    mainline/protocol/server/packet/itemspawn.cpp
    mainline/protocol/server/packet/login.cpp
    mainline/protocol/server/packet/message.cpp
    mainline/protocol/server/packet/mobspawn.cpp
    mainline/protocol/server/packet/movingobjectspawn.cpp
    mainline/protocol/server/packet/ping.cpp
    mainline/protocol/server/packet/playerlistitem.cpp
    mainline/protocol/server/packet/playerposdir.cpp
    mainline/protocol/server/packet/prechunk.cpp
    mainline/protocol/server/packet/spawnpoint.cpp
    mainline/protocol/server/packet/time.cpp
    mainline/protocol/server/packet/windowitems.cpp
)

set(${PROJECT_NAME}_headers_mainline_protocol_server
    ${${PROJECT_NAME}_headers_mainline_protocol_server_packet}
    mainline/protocol/server/packet.hpp
    mainline/protocol/server/protocol.hpp
)
set(${PROJECT_NAME}_sources_mainline_protocol_server
    ${${PROJECT_NAME}_sources_mainline_protocol_server_packet}
    mainline/protocol/server/protocol.cpp
)

set(${PROJECT_NAME}_headers_mainline_protocol
    ${${PROJECT_NAME}_headers_mainline_protocol_client}
    ${${PROJECT_NAME}_headers_mainline_protocol_packet}
    ${${PROJECT_NAME}_headers_mainline_protocol_server}
    mainline/protocol/client.hpp
    mainline/protocol/packet.hpp
    mainline/protocol/protocol.hpp
    mainline/protocol/stream.hpp
)
set(${PROJECT_NAME}_sources_mainline_protocol
    ${${PROJECT_NAME}_sources_mainline_protocol_client}
    ${${PROJECT_NAME}_sources_mainline_protocol_packet}
    ${${PROJECT_NAME}_sources_mainline_protocol_server}
    mainline/protocol/client.cpp
    mainline/protocol/stream.cpp
)

set(${PROJECT_NAME}_headers_mainline_session_remote_state
    mainline/session/remote/state/connecting.hpp
    mainline/session/remote/state/loading.hpp
    mainline/session/remote/state/negotiating.hpp
)
set(${PROJECT_NAME}_sources_mainline_session_remote_state
    mainline/session/remote/state/connecting.cpp
    mainline/session/remote/state/loading.cpp
    mainline/session/remote/state/negotiating.cpp
)

set(${PROJECT_NAME}_headers_mainline_session_remote
    ${${PROJECT_NAME}_headers_mainline_session_remote_state}
    mainline/session/remote/connection.hpp
    mainline/session/remote/state.hpp
)
set(${PROJECT_NAME}_sources_mainline_session_remote
    ${${PROJECT_NAME}_sources_mainline_session_remote_state}
    mainline/session/remote/connection.cpp
)

set(${PROJECT_NAME}_headers_mainline_session
    ${${PROJECT_NAME}_headers_mainline_session_remote}
    mainline/session/remote.hpp
)

set(${PROJECT_NAME}_sources_mainline_session
    ${${PROJECT_NAME}_sources_mainline_session_remote}
    mainline/session/remote.cpp
)

set(${PROJECT_NAME}_headers_mainline
    ${${PROJECT_NAME}_headers_mainline_game}
    ${${PROJECT_NAME}_headers_mainline_protocol}
    ${${PROJECT_NAME}_headers_mainline_session}
    mainline/client.hpp
    mainline/mctypes.hpp
    mainline/session.hpp
)
set(${PROJECT_NAME}_sources_mainline
    ${${PROJECT_NAME}_sources_mainline_game}
    ${${PROJECT_NAME}_sources_mainline_protocol}
    ${${PROJECT_NAME}_sources_mainline_session}
    mainline/client.cpp
    mainline/session.cpp
)

set(${PROJECT_NAME}_headers_shared_exception
    shared/exception/login.hpp
    shared/exception/map.hpp
    shared/exception/network.hpp
    shared/exception/protocol.hpp
)
set(${PROJECT_NAME}_sources_shared_exception
    shared/exception/login.cpp
    shared/exception/map.cpp
    shared/exception/network.cpp
    shared/exception/protocol.cpp
)

set(${PROJECT_NAME}_headers_shared_protocol
    shared/protocol/packet.hpp
    shared/protocol/protocol.hpp
    shared/protocol/packet.hpp
    shared/protocol/stream.hpp
)
set(${PROJECT_NAME}_sources_shared_protocol

)

set(${PROJECT_NAME}_headers_shared
    ${${PROJECT_NAME}_headers_shared_exception}
    ${${PROJECT_NAME}_headers_shared_protocol}
    shared/exception.hpp
    shared/mctypes.hpp
)
set(${PROJECT_NAME}_sources_shared
    ${${PROJECT_NAME}_sources_shared_exception}
    ${${PROJECT_NAME}_sources_shared_protocol}
    shared/exception.cpp
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
    ${${PROJECT_NAME}_headers_classic}
    ${${PROJECT_NAME}_headers_mainline}
    ${${PROJECT_NAME}_headers_shared}
    ${${PROJECT_NAME}_headers_support}
    ${${PROJECT_NAME}_headers_utils}
)
set (${PROJECT_NAME}_sources
    ${${PROJECT_NAME}_sources_classic}
    ${${PROJECT_NAME}_sources_mainline}
    ${${PROJECT_NAME}_sources_shared}
    ${${PROJECT_NAME}_sources_support}
    ${${PROJECT_NAME}_sources_utils}
)

# Includes
# ---------------
message("Boost_INCLUDE_DIR")
message(${Boost_INCLUDE_DIR})
include_directories(${Boost_INCLUDE_DIR})

# Pre-linkage Qt
# ---------------
INCLUDE(${QT_USE_FILE})

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

target_link_libraries(${PROJECT_NAME} ${Boost_LIBRARIES} ${QT_LIBRARIES})

# Install
# ---------------
install(TARGETS ${PROJECT_NAME}
                RUNTIME DESTINATION bin
                LIBRARY DESTINATION lib
                ARCHIVE DESTINATION lib/static)

OPTION(INSTALL_HEADERS "Copy headers to target" OFF)
IF(DEFINED INSTALL_HEADERS)
install(DIRECTORY . DESTINATION include/lib${PROJECT_NAME} FILES_MATCHING PATTERN "*.hpp")
ENDIF(DEFINED INSTALL_HEADERS)
