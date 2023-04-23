#ifndef SEKAI_ENGINE_API_VECTOR2D_HPP
#define SEKAI_ENGINE_API_VECTOR2D_HPP

#include "raylib.h"

namespace SekaiEngine
{
    namespace API
    {
        class Vector2D
        {
        public:
            Vector2D(const float &x = 0.0f, const float &y = 0.0f);
            explicit Vector2D(const ::Vector2 &vector);
            Vector2D(const Vector2D &vector);
            Vector2D &operator=(const Vector2D &vector);
            Vector2D &operator=(const ::Vector2 &vector);
            ~Vector2D();

            const Vector2D operator+(const Vector2D &vector);
            const Vector2D operator*(const float &scale);
            const bool operator==(const Vector2D& vector);

            const float &x() const;
            float &x();

            const float &y() const;
            float &y();

            const ::Vector2& get() const;
            const ::Vector2& get();

        private:
            ::Vector2 m_vector;
        };

        inline const float &Vector2D::x() const
        {
            return m_vector.x;
        }

        inline float &Vector2D::x()
        {
            return const_cast<float&>(static_cast<const Vector2D&>(*this).x());
        }

        inline const float &Vector2D::y() const
        {
            return m_vector.y;
        }

        inline float &Vector2D::y()
        {
            return const_cast<float&>(static_cast<const Vector2D&>(*this).y());
        }

        inline const ::Vector2& Vector2D::get() const
        {
            return m_vector;
        }

        inline const ::Vector2& Vector2D::get()
        {
            return static_cast<const Vector2D&>(*this).get();
        }
    } // namespace API

} // namespace SekaiEngine

#endif //! SEKAI_ENGINE_API_VECTOR2D_HPP