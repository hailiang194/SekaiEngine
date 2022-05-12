#ifndef _SEKAI_ENGINE_GRAPHIC_RECTANGLE_H_
    #define _SEKAI_ENGINE_GRAPHIC_RECTANGLE_H_

#include "../graphics/shape.h"

namespace SekaiEngine
{
    namespace Graphic
    {
        class Rectangle: public Shape
        {
        public:
            Rectangle(const Utility::Vector2D& position = Utility::Vector2D(), const float& width = 0.0f, const float& height = 0.0f);
            Rectangle(const Rectangle& rectangle);
            Rectangle& operator=(const Rectangle& rectangle);
            ~Rectangle();

            const Utility::Vector2D& position() const;
            Utility::Vector2D& position();

            const float& width() const;
            float& width();

            const float& height() const;
            float& height();

            const Transform2D drawGraphic(const Transform2D* parent = nullptr); 
        private:
            float m_width;
            float m_height;
        };

        inline const Utility::Vector2D& Rectangle::position() const
        {
            return m_self.position();
        }

        inline Utility::Vector2D& Rectangle::position()
        {
            return const_cast<Utility::Vector2D&>(static_cast<const Rectangle&>(*this).position());
        }

        inline const float& Rectangle::width() const
        {
            return m_width;
        }

        inline float& Rectangle::width()
        {
            return const_cast<float&>(static_cast<const Rectangle&>(*this).width());
        }

        inline const float& Rectangle::height() const
        {
            return m_height;
        }

        inline float& Rectangle::height()
        {
            return const_cast<float&>(static_cast<const Rectangle&>(*this).height());
        }
    } // namespace Graphic
    
} // namespace SekaiEngine


#endif //_SEKAI_ENGINE_GRAPHIC_RECTANGLE_H_