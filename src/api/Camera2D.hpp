#ifndef SEKAI_ENGINE_API_CAMERA_HPP
#define SEKAI_ENGINE_API_CAMERA_HPP

#include "raylib.h"
#include "./Vector2D.hpp"

namespace SekaiEngine
{
    namespace API
    {
        class Camera2D
        {
        public:
            Camera2D(const API::Vector2D& offset = API::Vector2D(), const API::Vector2D& target = API::Vector2D(), const float& rotation = 0.0f, const float& zoom = 1.0f);
            explicit Camera2D(const ::Camera2D& camera);
            Camera2D(const Camera2D& camera);
            Camera2D& operator=(const Camera2D& camera);
            Camera2D& operator=(const ::Camera2D& camera);
            ~Camera2D();

            void start();
            void end();

            const API::Vector2D& offset() const;
            API::Vector2D& offset();

            const API::Vector2D& target() const;
            API::Vector2D& target();

            const float& rotation() const;
            float& rotation();

            const float& zoom() const;
            float& zoom();
        private:
            API::Vector2D m_offset;
            API::Vector2D m_target;
            float m_rotation;
            float m_zoom;
        };

        inline const API::Vector2D& Camera2D::offset() const
        {
            return m_offset;
        }

        inline API::Vector2D& Camera2D::offset()
        {
            return const_cast<API::Vector2D&>(static_cast<const Camera2D&>(*this).offset());
        }

        inline const API::Vector2D& Camera2D::target() const
        {
            return m_target;
        }

        inline API::Vector2D& Camera2D::target()
        {
            return const_cast<API::Vector2D&>(static_cast<const Camera2D&>(*this).target());
        }

        inline const float& Camera2D::rotation() const
        {
            return m_rotation;
        }

        inline float& Camera2D::rotation()
        {
            return const_cast<float&>(static_cast<const Camera2D&>(*this).rotation());
        }

        inline const float& Camera2D::zoom() const
        {
            return m_zoom;
        }

        inline float& Camera2D::zoom()
        {
            return const_cast<float&>(static_cast<const Camera2D&>(*this).zoom());
        }
    } // namespace API
    
} // namespace SekaiEngine


#endif //!SEKAI_ENGINE_API_CAMERA_HPP