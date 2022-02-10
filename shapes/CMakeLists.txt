set(engine_shapes_public_headers
    point.h
    circle.h
)

set(engine_shapes_public_sources
    point.cpp
    circle.cpp
)

add_library(engine_shape ${engine_shapes_public_headers} ${engine_shapes_public_sources})
target_link_libraries(engine_shape PUBLIC raylib)