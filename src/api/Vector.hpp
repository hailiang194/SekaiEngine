#ifndef SEKAI_ENGINE_API_VECTOR2D_HPP
#define SEKAI_ENGINE_API_VECTOR2D_HPP

#include "./APIConfig.hpp"

namespace SekaiEngine
{
    namespace API
    {
        class Vector2D
        {
        public:
            Vector2D(const float &x = 0.0f, const float &y = 0.0f);
            explicit Vector2D(const VECTOR2_API &vector);
            Vector2D(const Vector2D &vector);
            Vector2D &operator=(const Vector2D &vector);
            Vector2D &operator=(const VECTOR2_API &vector);
            ~Vector2D();

            const Vector2D operator+(const Vector2D &vector) const;
            const Vector2D operator+(const Vector2D &vector);
            const Vector2D operator*(const float &scale) const;
            const Vector2D operator*(const float &scale);
            const Vector2D operator-(const Vector2D &vector) const;
            const Vector2D operator-(const Vector2D &vector);
            const bool operator==(const Vector2D& vector) const;
            const bool operator==(const Vector2D& vector);
            //dot product
            const float dot(const Vector2D& vector) const;
            const float dot(const Vector2D& vector);

            const float distance() const;
            const float distance();

            const float &x() const;
            float &x();

            const float &y() const;
            float &y();

            const VECTOR2_API get() const;
            const VECTOR2_API get();

        private:
            float m_x;
            float m_y;
        };

        inline const float &Vector2D::x() const
        {
            return m_x;
        }

        inline float &Vector2D::x()
        {
            return const_cast<float&>(static_cast<const Vector2D&>(*this).x());
        }

        inline const float &Vector2D::y() const
        {
            return m_y;
        }

        inline float &Vector2D::y()
        {
            return const_cast<float&>(static_cast<const Vector2D&>(*this).y());
        }

        inline const VECTOR2_API Vector2D::get() const
        {
#ifdef RAYLIB_API
            return VECTOR2_API{m_x, m_y};
#else

#endif
        }

        inline const VECTOR2_API Vector2D::get()
        {
            return static_cast<const Vector2D&>(*this).get();
        }
    } // namespace API

} // namespace SekaiEngine

#endif //! SEKAI_ENGINE_API_VECTOR2D_HPP