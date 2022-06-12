#ifndef _SEKAI_ENGINE_GRAPHIC_POINT_SHAPE_H_
    #define _SEKAI_ENGINE_GRAPHIC_POINT_SHAPE_H_

#include "../graphics/shape.h"

namespace SekaiEngine
{
    namespace Graphic
    {
        class Point2D: public Shape
        {
        public:
            Point2D(const Utility::Vector2D& position);
            Point2D(const Point2D& point);
            Point2D& operator=(const Point2D& point);
            ~Point2D();

            const Utility::Vector2D& position() const;
            Utility::Vector2D& position();
        protected:
            void computeTransform_() override;
            void render_() override;        
        };

        inline const Utility::Vector2D& Point2D::position() const
        {
            return m_self.position();
        }

        inline Utility::Vector2D& Point2D::position()
        {
            return const_cast<Utility::Vector2D&>(static_cast<const Point2D&>(*this).position());
        }
    } // namespace Graphic
    
} // namespace SekaiEngine


#endif