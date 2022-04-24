#include "vector2d.h"

namespace SekaiEngine
{
    namespace Utility
    {
        Vector2D::Vector2D(const float& x, const float& y)
            :m_x(x), m_y(y)
        {

        }

        Vector2D::Vector2D(const Vector2D& vector)
            :m_x(vector.m_x), m_y(vector.m_y)
        {

        }

        Vector2D& Vector2D::operator=(const Vector2D& vector)
        {
            m_x = vector.m_x;
            m_y = vector.m_y;

            return (*this);
        }

        Vector2D::~Vector2D()
        {

        }
    } // namespace Utility
    
} // namespace SekaiEngine
