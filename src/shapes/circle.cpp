#include "circle.h"

namespace SekaiEngine
{
    namespace Graphic
    {
        Circle2D::Circle2D(const Utility::Vector2D& center, const float& radius)
            :Shape(CIRCLE_SHAPE)
        {
            m_self.position() = center;
            m_self.scale() = radius;
        }

        Circle2D::Circle2D(const Circle2D& circle)
            :Shape(circle)
        {
        }

        Circle2D& Circle2D::operator=(const Circle2D& circle)
        {
            Shape::operator=(circle);
            return (*this);
        }

        Circle2D::~Circle2D()
        {

        }

        const Transform2D Circle2D::drawGraphic(const Transform2D* parent)
        {
            Transform2D transformed = (parent == nullptr) ? m_self : getTransformedValues(*parent, m_self);

            DrawCircleV(transformed.position().toRaylibVector(), transformed.scale(), transformed.color());
            
            return transformed;
        }
    } // namespace Graphic
    
} // namespace SekaiEngine
