#ifndef _SEKAI_ENGINE_INPUT_MOUSE_H_
    #define _SEKAI_ENGINE_INPUT_MOUSE_H_

#include "raylib.h"
#include "../utility/vector2d.h"

namespace SekaiEngine
{
    namespace Input
    {
        namespace Mouse
        {
            const bool pressed(const int& button);

            const bool down(const int& button);

            const bool up(const int& button);

            const bool released(const int& button);

            const Utility::Vector2D position();
        } // namespace Mouse
        
    } // namespace Input
    
} // namespace SekaiEngine


#endif //_SEKAI_ENGINE_INPUT_MOUSE_H_