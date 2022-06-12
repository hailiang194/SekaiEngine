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

        void Rectangle::computeTransform_()
        {
            Shape::computeTransform_();
        }

        void Rectangle::render_()
        {
            if(m_transformed.lineThick() == NO_LINE_THICK)
                DrawRectanglePro(
                    {m_transformed.position().x(), m_transformed.position().y(), m_transformed.scale() * m_width, m_transformed.scale() * m_height},
                    m_transformed.origin().toRaylibVector(),
                    m_transformed.rotation(),
                    m_transformed.color()
                );
            else //Bug if rotation
                DrawRectangleLinesEx(
                    {m_transformed.position().x(), m_transformed.position().y(), m_transformed.scale() * m_width, m_transformed.scale() * m_height},
                    m_transformed.lineThick(),
                    m_transformed.color()
                );
                
        }
    } // namespace Graphic
    
} // namespace SekaiEngine
