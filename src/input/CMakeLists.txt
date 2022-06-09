set(engine_input_public_headers
    keyboard.h
    mouse.h
    gamepad.h
    touch.h
    input-axis.h
    input-manager.h
)

set(engine_input_sources
    keyboard.cpp
    mouse.cpp
    gamepad.cpp
    touch.cpp
    input-axis.cpp
    input-manager.cpp
)

add_library(engine_input OBJECT ${engine_input_public_headers} ${engine_input_sources})
target_link_libraries(engine_input PRIVATE raylib)
file(COPY ${engine_input_public_headers} DESTINATION "${engine_include_dir}/${PROJECT_NAME}/input")