#ifndef SEKAI_ENGINE_API_CONFIG_HPP
#define SEKAI_ENGINE_API_CONFIG_HPP

#ifdef RAYLIB_API
#include "raylib.h"

#define CAMERA_API ::Camera2D
#define COLOR_API ::Color
#define MONITOR_CORE_TYPE int
#define VECTOR2_API ::Vector2

#else
#error "NO API"
#endif

#endif //!SEKAI_ENGINE_API_CONFIG_HPP