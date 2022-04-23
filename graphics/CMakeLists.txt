set(engine_graphic_public_headers
    graphic.h
    shape.h
    drawable.h
    transform2d.h
)

set(engine_graphic_sources
    graphic.cpp
    shape.cpp
    drawable.cpp
    transform2d.cpp
)

add_library(engine_graphic ${engine_graphic_public_headers} ${engine_graphic_sources})
target_link_libraries(engine_graphic PRIVATE raylib)