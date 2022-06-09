#include "keyboard.h"

namespace SekaiEngine
{
    namespace Input
    {
        namespace Keyboard
        {
            const bool pressed(const int& key)
            {
                return IsKeyPressed(key);
            }

            const bool down(const int& key)
            {
                return IsKeyDown(key);
            }

            const bool up(const int& key)
            {
                return IsKeyUp(key);
            }

            const bool released(const int& key)
            {
                return IsKeyReleased(key);
            }

            const int pressedKey()
            {
                return GetKeyPressed();
            }

            const int pressedChar()
            {
                return GetCharPressed();
            }
        } // namespace Keyboard
        
    } // namespace Input
    
} // namespace SekaiEngine
