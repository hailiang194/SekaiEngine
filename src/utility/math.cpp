#include "math.h"

namespace SekaiEngine
{
    namespace Math
    {
        int compareFloat(const float& first, const float& second, const float& epsilon)
        {
            if(std::fabs(first- second) < epsilon)
                return 0;

            return (first > second) ? 1: -1;
        }        
    } // namespace Math
    
} // namespace SekaiEngine


