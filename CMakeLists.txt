cmake_minimum_required(VERSION 3.1)
project(SekaiEngine VERSION 0.0.1)
set(CMAKE_CXX_STANDARD 11)

set(engine_include_dir "${CMAKE_CURRENT_BINARY_DIR}/include" CACHE STRING "Sekai Engine include headers path")
set(LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/libs)
add_subdirectory(vendors/raylib)


set(engine_public_headers
    src/core/application.h
    src/core/scence_manager.h
    src/core/game.h
    src/core/asset-manager.h
    src/graphics/graphic.h
    src/graphics/shape.h
    src/graphics/transform2d.h
    src/graphics/texture.h
    src/input/keyboard.h
    src/input/mouse.h
    src/input/gamepad.h
    src/input/touch.h
    src/input/input-axis.h
    src/input/input-manager.h
    src/objects/game_object.h
    src/objects/scence.h
    src/objects/sprite.h
    src/shapes/point.h
    src/shapes/circle.h
    src/shapes/line.h
    src/shapes/rectangle.h
    src/utility/vector2d.h
    src/utility/math.h
)

set(engine_sources
    src/core/application.cpp
    src/core/scence_manager.cpp
    src/core/game.cpp
    src/core/asset-manager.cpp
    src/graphics/graphic.cpp
    src/graphics/shape.cpp
    src/graphics/transform2d.cpp
    src/graphics/texture.cpp
    src/input/keyboard.cpp
    src/input/mouse.cpp
    src/input/gamepad.cpp
    src/input/touch.cpp
    src/input/input-axis.cpp
    src/input/input-manager.cpp
    src/objects/game_object.cpp
    src/objects/game_objects_container.cpp
    src/objects/scence.cpp
    src/objects/sprite.cpp
    src/shapes/point.cpp
    src/shapes/circle.cpp
    src/shapes/line.h
    src/shapes/rectangle.cpp
    src/utility/vector2d.cpp
    src/utility/math.cpp

)

# add_subdirectory(src/src/core)
# add_subdirectory(src/utility)
# add_subdirectory(src/objects)
# add_subdirectory(src/src/graphics)
# add_subdirectory(src/shapes)
# add_subdirectory(src/input)

# add_library(${PROJECT_NAME} INTERFACE)
# target_link_libraries
# add_library(${PROJECT_NAME} STATIC 
# $<TARGET_OBJECTS:engine_src/core> 
# $<TARGET_OBJECTS:engine_object>  
# $<TARGET_OBJECTS:engine_utility>  
# $<TARGET_OBJECTS:engine_graphic>  
# $<TARGET_OBJECTS:engine_shape>
# $<TARGET_OBJECTS:engine_input> 
# )

add_library(${PROJECT_NAME} STATIC ${engine_sources} ${engine_public_headers})
target_link_libraries(${PROJECT_NAME} raylib)
