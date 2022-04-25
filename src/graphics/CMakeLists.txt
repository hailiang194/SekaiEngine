set(engine_graphic_public_headers
    graphic.h
    shape.h
    transform2d.h
)

set(engine_graphic_sources
    graphic.cpp
    shape.cpp
    transform2d.cpp
)

add_library(engine_graphic OBJECT ${engine_graphic_public_headers} ${engine_graphic_sources})
target_link_libraries(engine_graphic PRIVATE raylib)
file(COPY ${engine_graphic_public_headers} DESTINATION "${engine_include_dir}/${PROJECT_NAME}/graphics")