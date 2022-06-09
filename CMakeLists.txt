cmake_minimum_required(VERSION 3.1)
project(SekaiEngine VERSION 0.0.1)
set(CMAKE_CXX_STANDARD 11)

set(engine_include_dir "${CMAKE_CURRENT_BINARY_DIR}/include" CACHE STRING "Sekai Engine include headers path")
set(LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/libs)
add_subdirectory(vendors/raylib)

add_subdirectory(src/core)
add_subdirectory(src/utility)
add_subdirectory(src/objects)
add_subdirectory(src/graphics)
add_subdirectory(src/shapes)
add_subdirectory(src/input)

# add_library(${PROJECT_NAME} INTERFACE)
# target_link_libraries
add_library(${PROJECT_NAME} STATIC 
$<TARGET_OBJECTS:engine_core> 
$<TARGET_OBJECTS:engine_object>  
$<TARGET_OBJECTS:engine_utility>  
$<TARGET_OBJECTS:engine_graphic>  
$<TARGET_OBJECTS:engine_shape>
$<TARGET_OBJECTS:engine_input> 
)

target_link_libraries(${PROJECT_NAME} raylib)
