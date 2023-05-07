#ifndef SEKAI_ENGINE_UTILITY_MATH_HPP
#define SEKAI_ENGINE_UTILITY_MATH_HPP

#include <cmath>

#define DEFAULT_EPSILON 0.0001f

namespace SekaiEngine
{
    namespace Utility
    {
        /// @brief Compare 2 float
        /// @param first first number
        /// @param second second number
        /// @param epsilon epsilon distance between 2 numbers to consider they are equal
        /// @return 1 if first > second, -1 if first < second and 0 if first == second
        const int cmpFloat(const float& first, const float& second, const float& epsilon = DEFAULT_EPSILON);
    } // namespace Utility
    
} // namespace SekaiEngine


#endif //!SEKAI_ENGINE_UTILITY_MATH_HPP