#ifndef _SEKAI_ENGINE_INPUT_KEYBOARD_H_
    #define _SEKAI_ENGINE_INPUT_KEYBOARD_H_

#include "raylib.h"

namespace SekaiEngine
{
    namespace Input
    {
        namespace Keyboard
        {
            const bool pressed(const int& key);

            const bool down(const int& key);

            const bool up(const int& key);

            const bool released(const int& key);

            const int pressedKey();

            const int pressedChar();
        } // namespace Keyboard
        
    } // namespace Input
    
} // namespace SekaiEngine


#endif //_SEKAI_ENGINE_INPUT_KEYBOARD_H_