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

        void Point2D::computeTransform_()
        {
            Shape::computeTransform_();
        }

        void Point2D::render_()
        {
            DrawPixelV(m_transformed.position().toRaylibVector(), m_transformed.color());
        }
    } // namespace Graphic
    
} // namespace SekaiEngine
