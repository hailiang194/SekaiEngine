#include "point.h"

namespace SekaiEngine
{
    namespace Graphic
    {
        Point2D::Point2D(const Utility::Vector2D& position)
            :Shape(POINT_SHAPE)
        {
            m_self.position() = position;
        }

        Point2D::Point2D(const Point2D& point)
            :Shape(point)
        {

        }

        Point2D& Point2D::operator=(const Point2D& point)
        {
            Shape::operator=(point);

            return (*this);
        }

        Point2D::~Point2D()
        {
            
        }

        const Transform2D Point2D::drawGraphic(const Transform2D* parent)
        {
            Transform2D transformed = (parent == nullptr) ? m_self : getTransformedValues(*parent, m_self);

            DrawPixelV(transformed.position().toRaylibVector(), transformed.color());

            return transformed;
        }
    } // namespace Graphic
    
} // namespace SekaiEngine
