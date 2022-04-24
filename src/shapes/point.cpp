#include "point.h"

namespace SekaiEngine
{
    namespace Graphic
    {
        Point2D::Point2D(const Utility::Vector2D& position)
            :Shape(POINT_SHAPE)
        {

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
    } // namespace Graphic
    
} // namespace SekaiEngine
