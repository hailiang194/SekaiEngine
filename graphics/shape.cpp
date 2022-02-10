#include "shape.h"

namespace SekaiEngine
{
    namespace Graphic
    {
            Shape::Shape(const ShapeFlag& SHAPE_FLAG)
                :Object::GameObject(), m_SHAPE_FLAG(SHAPE_FLAG)
            {

            }

            Shape::Shape(const Shape& shape)
                :Object::GameObject(shape), m_SHAPE_FLAG(shape.m_SHAPE_FLAG)
            {

            }

            Shape& Shape::operator=(const Shape& shape)
            {
                Object::GameObject::operator=(shape);
                const_cast<ShapeFlag&>(m_SHAPE_FLAG) = shape.m_SHAPE_FLAG;
                return (*this);
            }

            Shape::~Shape()
            {

            }

            void Shape::setup()
            {
                Object::GameObject::setup();
            }

            void Shape::update()
            {
                Object::GameObject::update();
            }

            void Shape::draw()
            {
                Object::GameObject::draw();
            }

            void Shape::kill()
            {
                Object::GameObject::kill();
            }
    } // namespace Graphic
    
} // namespace SekaiEngine
