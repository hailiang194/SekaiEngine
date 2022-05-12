set(engine_core_public_headers
    application.h
    scence_manager.h
    game.h
    asset-manager.h
)

set(engine_core_sources
    application.cpp
    scence_manager.cpp
    game.cpp
    asset-manager.cpp
)

add_library(engine_core OBJECT ${engine_core_public_headers} ${engine_core_sources})
target_link_libraries(engine_core PUBLIC raylib)
file(COPY ${engine_core_public_headers} DESTINATION "${engine_include_dir}/${PROJECT_NAME}/core")