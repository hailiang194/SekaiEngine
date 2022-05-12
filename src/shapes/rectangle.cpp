#include "rectangle.h"

namespace SekaiEngine
{
    namespace Graphic
    {
        Rectangle::Rectangle(const Utility::Vector2D& position, const float& width, const float& height)
            :Shape(RECTANGLE_SHAPE), m_width(width), m_height(height)
        {
            m_self.position() = position;
        }

        Rectangle::Rectangle(const Rectangle& rectangle)
            :Shape(rectangle), m_width(rectangle.m_width), m_height(rectangle.m_height)
        {

        }

        Rectangle& Rectangle::operator=(const Rectangle& rectangle)
        {
            Shape::operator=(rectangle);
            m_width = rectangle.m_width;
            m_height = rectangle.m_height;

            return (*this);
        }

        Rectangle::~Rectangle()
        {

        }

        const Transform2D Rectangle::drawGraphic(const Transform2D* parent)
        {
            Transform2D transformed = (parent == nullptr) ? m_self : getTransformedValues(*parent, m_self);

            DrawRectanglePro(
                {transformed.position().x(), transformed.position().y(), transformed.scale() * m_width, transformed.scale() * m_height},
                transformed.origin().toRaylibVector(),
                transformed.rotation(),
                transformed.color()
            );
            
            return transformed;
        }
    } // namespace Graphic
    
} // namespace SekaiEngine
