project(SekaiEngine VERSION 0.0.1)
set(CMAKE_CXX_STANDARD 11)

add_subdirectory(raylib)

add_subdirectory(core)
add_subdirectory(utility)
add_subdirectory(objects)
add_subdirectory(graphics)
add_subdirectory(shapes)
add_subdirectory(drawable)

add_library(${PROJECT_NAME} INTERFACE)
target_link_libraries(${PROJECT_NAME} INTERFACE 
  engine_core 
  engine_object
  engine_utility
  engine_graphic
  engine_shape
  engine_drawable
)

# I don't know why, but It's work :v
target_include_directories(engine_core PUBLIC ${CMAKE_SOURCE_DIR})
target_include_directories(engine_object PUBLIC ${CMAKE_SOURCE_DIR})


