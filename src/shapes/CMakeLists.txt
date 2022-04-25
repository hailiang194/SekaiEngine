set(engine_shapes_public_headers
    point.h
    circle.h
    line.h
    rectangle.h
)

set(engine_shapes_public_sources
    point.cpp
    circle.cpp
    line.h
    rectangle.cpp
)

add_library(engine_shape OBJECT ${engine_shapes_public_headers} ${engine_shapes_public_sources})
target_link_libraries(engine_shape PUBLIC raylib)
file(COPY ${engine_shapes_public_headers} DESTINATION "${engine_include_dir}/${PROJECT_NAME}/shapes")