#ifndef _SEKAI_ENGINE_GRAPHIC_POINT_SHAPE_H_
    #define _SEKAI_ENGINE_GRAPHIC_POINT_SHAPE_H_

#include "../graphics/shape.h"
#include "../utility/vector2d.h"

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
            virtual ~Point2D();

            const Utility::Vector2D& position() const;
            Utility::Vector2D& position();
        protected:
            Utility::Vector2D m_position;
        };

        inline const Utility::Vector2D& Point2D::position() const
        {
            return m_position;
        }

        inline Utility::Vector2D& Point2D::position()
        {
            return const_cast<Utility::Vector2D&>(static_cast<const Point2D&>(*this).position());
        }
    } // namespace Graphic
    
} // namespace SekaiEngine


#endif