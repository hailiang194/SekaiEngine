#ifndef _SEKAI_ENGINE_GRAPHIC_CIRCLE_SHAPE_H_
    #define _SEKAI_ENGINE_GRAPHIC_CIRCLE_SHAPE_H_

#include "../graphics/shape.h"

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

            const Transform2D drawGraphic(const Transform2D* parent = nullptr) override;
        };

        inline const Utility::Vector2D& Circle2D::center() const
        {
            return m_self.position();
        }

        inline Utility::Vector2D& Circle2D::center()
        {
            return const_cast<Utility::Vector2D&>(static_cast<const Circle2D&>(*this).center());
        }

        inline const float& Circle2D::radius() const
        {
            return m_self.scale();
        }

        inline float& Circle2D::radius()
        {
            return const_cast<float&>(static_cast<const Circle2D&>(*this).radius());
        }
    } // namespace Graphic
    
} // namespace SekaiEngine


#endif