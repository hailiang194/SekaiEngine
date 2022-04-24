#ifndef _SEKAI_ENGINE_GRAPHIC_TRANFORM_2D_H_
#define _SEKAI_ENGINE_GRAPHIC_TRANFORM_2D_H_

#include "raylib.h"
#include "../utility/vector2d.h"

namespace SekaiEngine
{
    namespace Graphic
    {
        class Transform2D
        {
        public:
            Transform2D(
                const Utility::Vector2D& position = Utility::Vector2D(),
                const float& scale = 1.0f,
                const Utility::Vector2D& origin = Utility::Vector2D(),
                const float& rotation = 0.0f,
                const Color& color = WHITE
            );
            Transform2D(const Transform2D& transform);
            Transform2D& operator=(const Transform2D& transfrom);
            virtual ~Transform2D();

            const Utility::Vector2D& position() const;
            Utility::Vector2D& position();

            const float& scale() const;
            float& scale();

            const Utility::Vector2D& origin() const;
            Utility::Vector2D& origin();

            const float& rotation() const;
            float& rotation();

            const Color& color() const;
            Color& color();

        protected:
            Utility::Vector2D m_position;
            float m_scale;
            Utility::Vector2D m_origin;
            float m_rotation;
            Color m_color;
        };

        const Transform2D getTransformedValues(const Transform2D& parent, const Transform2D& self);

        inline const Utility::Vector2D& SekaiEngine::Graphic::Transform2D::position() const
        {
            return m_position;
        }

        inline Utility::Vector2D& Transform2D::position()
        {
            return const_cast<Utility::Vector2D&>(static_cast<const Transform2D&>(*this).position());
        }

        inline const float& Transform2D::scale() const
        {
            return m_scale;
        }

        inline float& Transform2D::scale()
        {
            return const_cast<float&>(static_cast<const Transform2D&>(*this).scale());
        }

        inline const Utility::Vector2D& Transform2D::origin() const
        {
            return m_origin;
        }

        inline Utility::Vector2D& Transform2D::origin()
        {
            return const_cast<Utility::Vector2D&>(static_cast<const Transform2D&>(*this).origin());
        }

        inline const float& Transform2D::rotation() const
        {
            return m_rotation;
        }
        inline float& Transform2D::rotation()
        {
            return const_cast<float&>(static_cast<const Transform2D&>(*this).rotation());
        }

        inline const Color& Transform2D::color() const
        {
            return m_color;
        }

        inline Color& Transform2D::color()
        {
            return const_cast<Color&>(static_cast<const Transform2D&>(*this).color());
        }

    } // namespace Graphic
    
} // namespace SekaiEngine


#endif //_SEKAI_ENGINE_GRAPHIC_TRANFORM_2D_H_