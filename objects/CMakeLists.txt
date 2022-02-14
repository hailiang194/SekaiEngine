set(engine_object_public_headers
    game_object.h
    # game_objects_container.h
    scence.h
    sprite.h
)

set(engine_object_sources
    game_object.cpp
    game_objects_container.cpp
    scence.cpp
    sprite.cpp
)

add_library(engine_object STATIC ${engine_object_public_headers} ${engine_object_sources})
target_link_libraries(engine_object PRIVATE raylib)

# add_library(engine_object_game_object game_object.h game_object.cpp)
# target_link_libraries(engine_object_game_object PRIVATE raylib)

# add_library(engine_object_scence scence.h scence.cpp)
# target_link_libraries(engine_object_scence PRIVATE raylib)