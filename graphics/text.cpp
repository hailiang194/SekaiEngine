#include "text.h"

namespace SekaiEngine
{
    namespace Graphic
    {
            Text::Text(const std::string& text, const Color& tint, const Utility::Vector2D& position, const Font& font, const float& fontSize, const float& spacing, const Utility::Vector2D& origin, const float& rotation)
                :Object::GameObject(true), m_content(text), m_tint(tint), m_position(position),
                m_font(font), m_fontSize(fontSize), m_spacing(spacing), 
                m_origin(origin), m_rotation(rotation)
            {

            }

            Text::Text(const Text& text)
                :Object::GameObject(text), m_content(text.m_content), m_tint(text.m_tint), m_position(text.m_position),
                m_font(text.m_font), m_fontSize(text.m_fontSize), m_spacing(text.m_spacing),
                m_origin(text.m_origin), m_rotation(text.m_rotation)
            {

            }

            Text& Text::operator=(const Text& text)
            {
                Object::GameObject::operator=(text);
                m_content = text.m_content;
                m_tint = text.m_tint;
                m_position = text.m_position;
                m_font = text.m_font;
                m_fontSize = text.m_fontSize;
                m_spacing = text.m_spacing;
                m_origin = text.m_origin;
                m_rotation = text.m_rotation;

                return (*this);
            }

            Text::~Text()
            {

            }

            void Text::setup()
            {
                Object::GameObject::setup();
            }
            
            void Text::update()
            {
                Object::GameObject::update();
            }

            void Text::draw()
            {
                Object::GameObject::draw();
                DrawTextPro(m_font, m_content.c_str(), m_position.toRaylibVector(), m_origin.toRaylibVector(), m_rotation, m_fontSize, m_spacing, m_tint);
            }

            void Text::kill()
            {
                Object::GameObject::kill();
            }
    } // namespace Graphic
    
} // namespace SekaiEngine
