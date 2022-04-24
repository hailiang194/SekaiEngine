#ifndef _SEKAI_ENGINE_MATH_H_
    #define _SEKAI_ENGINE_MATH_H_

#include <cmath>
#include <functional>

namespace SekaiEngine
{
    namespace Math
    {
        typedef std::function<const float(const float&)> InjectiveFunction;
        int compareFloat(const float& first, const float& second, const float& epsilon = 0.0001f);        
    } // namespace Math
    
} // namespace SekaiEngine

#endif //_SEKAI_ENGINE_MATH_H_ 