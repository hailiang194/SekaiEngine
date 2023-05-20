#ifndef SEKAI_ENGINE_RENDERABLE_RENDERABLE_PROPERTIES_HPP
#define SEKAI_ENGINE_RENDERABLE_RENDERABLE_PROPERTIES_HPP

#include <cassert>
#include <api/Color.hpp>
#include <api/Vector.hpp>

#define FILL_THICK -1.0f

namespace SekaiEngine
{
    namespace Renderable
    {
        class RenderableProperties
        {
        public:
            RenderableProperties(API::Vector2D* offset = nullptr);
            RenderableProperties(const RenderableProperties& properties);
            RenderableProperties& operator=(const RenderableProperties& properties);
            ~RenderableProperties();

            const API::Color& color() const;
            API::Color& color();

            const float& thick() const;
            float& thick();

            const API::Vector2D& scale() const;
            API::Vector2D& scale();

            const float& startAngle() const;
            float& startAngle();

            const float& endAngle() const;
            float& endAngle();

            const int& segments() const;
            int& segments();

            const API::Vector2D& origin() const;
            API::Vector2D& origin();

            const float& rotation() const;
            float& rotation();

            const API::Vector2D* offset() const;
            const API::Vector2D* offset();

            void updateOffset(const API::Vector2D& offset);
        private:
            //basic draw
            API::Color m_color;
            float m_thick;
            //scale
            API::Vector2D m_scale;
            //for circle, ring, etc
            float m_startAngle; // this is in degree
            float m_endAngle; // this is in degree
            int m_segments;
            //rotation
            API::Vector2D m_origin;
            float m_rotation;
            //offset position
            API::Vector2D* m_offset;
            bool m_standaloneOffset;
        };

        inline const API::Color& RenderableProperties::color() const
        {
            return m_color;
        }

        inline API::Color& RenderableProperties::color()
        {
            return const_cast<API::Color&>(static_cast<const RenderableProperties&>(*this).color());
        }

        inline const float& RenderableProperties::thick() const
        {
            return m_thick;
        }

        inline float& RenderableProperties::thick()
        {
            return const_cast<float&>(static_cast<const RenderableProperties&>(*this).thick());
        }

        inline const API::Vector2D& RenderableProperties::scale() const
        {
            return m_scale;
        }

        inline API::Vector2D& RenderableProperties::scale()
        {
            return const_cast<API::Vector2D&>(static_cast<const RenderableProperties&>(*this).scale());
        }

        inline const float& RenderableProperties::startAngle() const
        {
            return m_startAngle;
        }

        inline float& RenderableProperties::startAngle()
        {
            return const_cast<float&>(static_cast<const RenderableProperties&>(*this).startAngle());
        }

        inline const float& RenderableProperties::endAngle() const
        {
            return m_endAngle;
        }

        inline float& RenderableProperties::endAngle()
        {
            return const_cast<float&>(static_cast<const RenderableProperties&>(*this).endAngle());
        }

        inline const int& RenderableProperties::segments() const
        {
            return m_segments;
        }

        inline int& RenderableProperties::segments()
        {
            return const_cast<int&>(static_cast<const RenderableProperties&>(*this).segments());
        }

        inline const API::Vector2D& RenderableProperties::origin() const
        {
            return m_origin;
        }

        inline API::Vector2D& RenderableProperties::origin()
        {
            return const_cast<API::Vector2D&>(static_cast<const RenderableProperties&>(*this).origin());
        }

        inline const float& RenderableProperties::rotation() const
        {
            return m_rotation;
        }

        inline float& RenderableProperties::rotation()
        {
            return const_cast<float&>(static_cast<const RenderableProperties&>(*this).rotation());
        }

        inline const API::Vector2D* RenderableProperties::offset() const
        {
            return m_offset;
        }

        inline const API::Vector2D* RenderableProperties::offset()
        {
            return static_cast<const RenderableProperties&>(*this).offset();
        }

        inline void RenderableProperties::updateOffset(const API::Vector2D& offset)
        {
            assert(!m_standaloneOffset);
            *m_offset = offset;
        }

    } // namespace Renderable
    
} // namespace SekaiEngine


#endif //!SEKAI_ENGINE_RENDERABLE_RENDERABLE_PROPERTIES_HPP