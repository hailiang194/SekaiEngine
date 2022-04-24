project(SekaiEngine VERSION 0.0.1)
set(CMAKE_CXX_STANDARD 11)

set(engine_include_dir "${CMAKE_CURRENT_BINARY_DIR}/include" CACHE STRING "Sekai Engine include headers path")

add_subdirectory(vendors/raylib)

add_subdirectory(src/core)
add_subdirectory(src/utility)
add_subdirectory(src/objects)
add_subdirectory(src/graphics)
add_subdirectory(src/shapes)

add_library(${PROJECT_NAME} INTERFACE)
target_link_libraries(${PROJECT_NAME} INTERFACE 
  engine_core 
  engine_object
  engine_utility
  engine_graphic
  engine_shape
)

