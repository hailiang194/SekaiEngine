set(engine_graphic_public_headers
    text.h
)

set(engine_graphic_sources
    text.cpp
)

add_library(engine_graphic ${engine_graphic_public_headers} ${engine_graphic_sources})
target_link_libraries(engine_graphic PRIVATE raylib)