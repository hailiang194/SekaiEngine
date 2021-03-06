#include "shape.h"

namespace SekaiEngine
{
    namespace Graphic
    {
            Shape::Shape(const ShapeFlag& SHAPE_FLAG, const Transform2D& self)
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
                m_SHAPE_FLAG = shape.m_SHAPE_FLAG;
                return (*this);
            }

            void Shape::computeTransform_()
            {
                Graphic::computeTransform_();
            }

            Shape::~Shape()
            {

            }
    } // namespace Graphic
    
} // namespace SekaiEngine
