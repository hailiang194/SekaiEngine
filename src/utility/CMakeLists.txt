set(engine_utility_public_headers
    vector2d.h
    math.h
)

set(engine_utility_sources
    vector2d.cpp
    math.cpp
)

add_library(engine_utility OBJECT ${engine_utility_public_headers} ${engine_utility_sources})
target_link_libraries(engine_utility PRIVATE raylib)
file(COPY ${engine_utility_public_headers} DESTINATION "${engine_include_dir}/${PROJECT_NAME}/utility")