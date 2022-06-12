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

        void Circle2D::computeTransform_()
        {
            Shape::computeTransform_();
        }

        void Circle2D::render_()
        {
            if(m_transformed.lineThick() == NO_LINE_THICK)
                DrawCircleV(m_transformed.position().toRaylibVector(), m_transformed.scale(), m_transformed.color());
            else
                DrawRing(m_transformed.position().toRaylibVector(), m_transformed.scale(), m_transformed.scale() - m_transformed.lineThick(), 0, 360, 36, m_transformed.color());
        }
    } // namespace Graphic
    
} // namespace SekaiEngine
