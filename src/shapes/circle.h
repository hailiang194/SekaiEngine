#ifndef _SEKAI_ENGINE_GRAPHIC_CIRCLE_SHAPE_H_
    #define _SEKAI_ENGINE_GRAPHIC_CIRCLE_SHAPE_H_

#include "../graphics/shape.h"
#include "../utility/vector2d.h"

namespace SekaiEngine
{
    namespace Graphic
    {
        class Circle2D: public Shape
        {
        public:
            Circle2D(const Utility::Vector2D& center, const float& radius);
            Circle2D(const Circle2D& circle);
            Circle2D& operator=(const Circle2D& circle);
            ~Circle2D();

            const Utility::Vector2D& center() const;
            Utility::Vector2D& center();

            const float& radius() const;
            float& radius();
        protected:
            Utility::Vector2D m_center;
            float m_radius;
        };

        inline const Utility::Vector2D& Circle2D::center() const
        {
            return m_center;
        }

        inline Utility::Vector2D& Circle2D::center()
        {
            return const_cast<Utility::Vector2D&>(static_cast<const Circle2D&>(*this).center());
        }

        inline const float& Circle2D::radius() const
        {
            return m_radius;
        }

        inline float& Circle2D::radius()
        {
            return const_cast<float&>(static_cast<const Circle2D&>(*this).radius());
        }
    } // namespace Graphic
    
} // namespace SekaiEngine


#endif