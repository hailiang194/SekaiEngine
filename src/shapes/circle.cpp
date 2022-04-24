#include "circle.h"

namespace SekaiEngine
{
    namespace Graphic
    {
        Circle2D::Circle2D(const Utility::Vector2D& center, const float& radius)
            :Shape(CIRCLE_SHAPE), m_center(center), m_radius(radius)
        {

        }

        Circle2D::Circle2D(const Circle2D& circle)
            :Shape(circle), m_center(circle.m_center), m_radius(circle.m_radius)
        {

        }

        Circle2D& Circle2D::operator=(const Circle2D& circle)
        {
            Shape::operator=(circle);

            m_center = circle.m_center;
            m_radius = circle.m_radius;

            return (*this);
        }

        Circle2D::~Circle2D()
        {

        }
    } // namespace Graphic
    
} // namespace SekaiEngine
