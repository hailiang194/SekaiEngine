#ifndef _SEKAI_ENGINE_GRAPHIC_LINE_H_
    #define _SEKAI_ENGINE_GRAPHIC_LINE_H_


#include "../graphics/shape.h"

namespace SekaiEngine
{
    namespace Graphic
    {
        class Line: public Shape
        {
        public:
            Line(const Utility::Vector2D& startPoint = Utility::Vector2D(), const Utility::Vector2D& endPoint = Utility::Vector2D());
            Line(const Line& line);
            Line& operator=(const Line& line);
            ~Line();
            const Utility::Vector2D& startPoint() const;
            Utility::Vector2D& startPoint();

            const Utility::Vector2D& endPoint() const;
            Utility::Vector2D& endPoint();
        protected:
            void computeTransform_() override;
            void render_() override;
        private:
            Utility::Vector2D m_endPoint;
        };

        inline const Utility::Vector2D& Line::startPoint() const
        {
            return m_self.position();
        }

        inline Utility::Vector2D& Line::startPoint()
        {
            return const_cast<Utility::Vector2D&>(static_cast<const Line&>(*this).startPoint());
        }

        inline const Utility::Vector2D& Line::endPoint() const
        {
            return m_endPoint;
        }

        inline Utility::Vector2D& Line::endPoint()
        {
            return const_cast<Utility::Vector2D&>(static_cast<const Line&>(*this).endPoint());
        }
    } // namespace Graphic
    
} // namespace SekaiEngine

#endif //_SEKAI_ENGINE_GRAPHIC_LINE_H_