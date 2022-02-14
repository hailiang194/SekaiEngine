#ifndef _SEKAI_ENGINE_GRAPHIC_TEXT_H_
    #define _SEKAI_ENGINE_GRAPHIC_TEXT_H_

#include "../objects/game_object.h"
#include "../utility/vector2d.h"
#include <string>

namespace SekaiEngine
{
    namespace Graphic
    {
        class Text: public Object::GameObject
        {
        public:
            Text(const std::string& text, const Color& tint, const Utility::Vector2D& position = Utility::Vector2D(), const Font& font = GetFontDefault(), const float& fontSize = 10.0f, const float& spacing = 1.0f, const Utility::Vector2D& origin = {0.0f, 0.0f}, const float& rotation = 0.0f, const int& zIndex = 0);
            Text(const Text& text);
            Text& operator=(const Text& text);
            virtual ~Text();

            const std::string& content() const;
            std::string& content();

            const Color& tint() const;
            Color& tint();

            const Utility::Vector2D& position() const;
            Utility::Vector2D& position();

            const Font& font() const;
            Font& font();

            const float& fontSize() const;
            float& fontSize();

            const float& spacing() const;
            float& spacing();

            const Utility::Vector2D& origin() const;
            Utility::Vector2D& origin();

            const float& rotation() const;
            float& rotation();

            virtual void setup();
            
            virtual void update();

            virtual void draw();

            virtual void kill();

        protected:
            std::string m_content;
            Color m_tint;
            Utility::Vector2D m_position;
            Font m_font;
            float m_fontSize;
            float m_spacing;
            Utility::Vector2D m_origin;
            float m_rotation;
        };

        inline const std::string& Text::content() const
        {
            return m_content;
        }

        inline std::string& Text::content()
        {
            return const_cast<std::string&>(static_cast<const Text&>(*this).content());
        }

        inline const Color& Text::tint() const
        {
            return m_tint;
        }

        inline Color& Text::tint()
        {
            return const_cast<Color&>(static_cast<const Text&>(*this).tint());
        }

        inline const Utility::Vector2D& Text::position() const
        {
            return m_position;
        }

        inline Utility::Vector2D& Text::position()
        {
            return const_cast<Utility::Vector2D&>(static_cast<const Text&>(*this).position());
        }

        inline const Font& Text::font() const
        {
            return m_font;
        }

        inline Font& Text::font()
        {
            return const_cast<Font&>(static_cast<const Text&>(*this).font());
        }

        inline const float& Text::fontSize() const
        {
            return m_fontSize;
        }

        inline float& Text::fontSize()
        {
            return const_cast<float&>(static_cast<const Text&>(*this).fontSize());
        }

        inline const float& Text::spacing() const
        {
            return m_spacing;
        }

        inline float& Text::spacing()
        {
            return const_cast<float&>(static_cast<const Text&>(*this).spacing());
        }

        inline const Utility::Vector2D& Text::origin() const
        {
            return m_origin;
        }

        inline Utility::Vector2D& Text::origin()
        {
            return const_cast<Utility::Vector2D&>(static_cast<const Text&>(*this).origin());
        }

        inline const float& Text::rotation() const
        {
            return m_rotation;
        }

        inline float& Text::rotation()
        {
            return const_cast<float&>(static_cast<const Text&>(*this).rotation());
        }
    } // namespace Graphic
    
} // namespace SekaiEngine


#endif //_SEKAI_ENGINE_GRAPHIC_TEXT_H_