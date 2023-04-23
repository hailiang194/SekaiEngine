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
    } // namespace API
    
} // namespace SekaiEngine


#endif //!SEKAI_ENGINE_API_CAMERA_HPP