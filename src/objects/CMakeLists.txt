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

add_library(engine_object OBJECT ${engine_object_public_headers} ${engine_object_sources})
target_link_libraries(engine_object PRIVATE raylib)
file(COPY ${engine_object_public_headers} DESTINATION "${engine_include_dir}/${PROJECT_NAME}/objects")