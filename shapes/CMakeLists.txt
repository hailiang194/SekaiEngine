set(engine_shapes_public_headers
    point.h
)

set(engine_shapes_public_sources
    point.cpp
)

add_library(engine_shape ${engine_shapes_public_headers} ${engine_shapes_public_sources})
target_link_libraries(engine_shape PUBLIC raylib)