#include <cmath>
#include "./math.hpp"

const int SekaiEngine::Utility::cmpFloat(const float &first, const float &second, const float &epsilon)
{
    if (std::fabs(first - second) < epsilon)
        return 0;

    return (first > second) ? 1 : -1;
}