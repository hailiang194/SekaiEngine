#ifndef _SEKAI_ENGINE_INPUT_TOUCH_H_
#define _SEKAI_ENGINE_INPUT_TOUCH_H_

#include "raylib.h"
#include "../utility/vector2d.h"

namespace SekaiEngine
{
    namespace Input
    {
        namespace Touch
        {
            const int totalTouchPoint();
            const Utility::Vector2D getTouchPoisition(const int& index);
        } // namespace Touch
        
    } // namespace Input
    
} // namespace SekaiEngine


#endif //_SEKAI_ENGINE_INPUT_TOUCH_H_