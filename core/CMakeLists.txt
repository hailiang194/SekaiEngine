set(engine_core_public_headers
    application.h
    scence_manager.h
    game.h
)

set(engine_core_sources
    application.cpp
    scence_manager.cpp
    game.cpp
)

add_library(engine_core STATIC ${engine_core_public_headers} ${engine_core_sources})
target_link_libraries(engine_core PUBLIC raylib)

