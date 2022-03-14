set(engine_drawable_public_headers
    SingleColorDrawable.h
    LineDrawable.h
    GradientDrawable.h
    RotationDrawable.h
    ScaleDrawable.h
)

set(engine_drawable_sources
    SingleColorDrawable.cpp
    LineDrawable.cpp
    GradientDrawable.cpp
    RotationDrawable.cpp
    ScaleDrawable.cpp
)

add_library(engine_drawable ${engine_drawable_public_headers} ${engine_drawable_sources})
target_link_libraries(engine_drawable PUBLIC raylib)