#include "mouse.h"

namespace SekaiEngine
{
    namespace Input
    {
        namespace Mouse
        {
            const bool pressed(const int& button)
            {
                return IsMouseButtonPressed(button);
            }

            const bool down(const int& button)
            {
                return IsMouseButtonDown(button);
            }

            const bool up(const int& button)
            {
                return IsMouseButtonUp(button);
            }

            const bool released(const int& button)
            {
                return IsMouseButtonReleased(button);
            }

            const Utility::Vector2D position()
            {
                return Utility::Vector2D(GetMouseX(), GetMouseY());
            }
        } // namespace Mouse
        
    } // namespace Input
    
} // namespace SekaiEngine
