#include "shape.h"

namespace SekaiEngine
{
    namespace Graphic
    {
            Shape::Shape(const ShapeFlag& SHAPE_FLAG)
                :Graphic(), m_SHAPE_FLAG(SHAPE_FLAG)
            {

            }

            Shape::Shape(const Shape& shape)
                :Graphic::Graphic(shape), m_SHAPE_FLAG(shape.m_SHAPE_FLAG)
            {

            }

            Shape& Shape::operator=(const Shape& shape)
            {
                Graphic::operator=(shape);
                const_cast<ShapeFlag&>(m_SHAPE_FLAG) = shape.m_SHAPE_FLAG;
                return (*this);
            }

            Shape::~Shape()
            {

            }
    } // namespace Graphic
    
} // namespace SekaiEngine
