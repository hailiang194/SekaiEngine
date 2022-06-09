#include "touch.h"

namespace SekaiEngine
{
    namespace Input
    {
        namespace Touch
        {
            const int totalTouchPoint()
            {
                return GetTouchPointCount();
            }

            const Utility::Vector2D getTouchPoisition(const int& index)
            {

                return Utility::Vector2D();
            }
        } // namespace Touch
        
    } // namespace Input
    
} // namespace SekaiEngine
