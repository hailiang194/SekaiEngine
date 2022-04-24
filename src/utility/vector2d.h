#ifndef _SEKAI_ENGINE_UTILITY_VECTOR_2D_H_
    #define _SEKAI_ENGINE_UTILITY_VECTOR_2D_H_

#include <cmath>
#include "raymath.h"
#include "math.h"

namespace SekaiEngine
{
    namespace Utility
    {
        class Vector2D
        {
        public:
            Vector2D(const float& x = 0.0f, const float& y = 0.0f);
            Vector2D(const Vector2D& vector);
            Vector2D& operator=(const Vector2D& vector);
            ~Vector2D();

            const float& x() const;
            float& x();

            const float& y() const;
            float& y();

            const float distance() const;
            const float distance();

            const Vector2D operator+(const Vector2D& vector);
            const Vector2D operator+(const Vector2D& vector) const;
            const Vector2D operator*(const float& scale);
            const Vector2D operator*(const float& scale) const;
            const bool operator==(const Vector2D& vector);
            const bool operator==(const Vector2D& vector) const;

            const Vector2 toRaylibVector() const;
            const Vector2 toRaylibVector();

        private:
            float m_x;
            float m_y;
        };

        inline const float& Vector2D::x() const
        {
            return m_x;
        }

        inline float& Vector2D::x()
        {
            return const_cast<float&>(static_cast<const Vector2D&>(*this).x());
        }

        inline const float& Vector2D::y() const
        {
            return m_y;
        }

        inline float& Vector2D::y()
        {
            return const_cast<float&>(static_cast<const Vector2D&>(*this).y());
        }

        inline const float Vector2D::distance() const
        {
            return std::sqrt(m_x * m_x + m_y * m_y);
        }

        inline const Vector2D Vector2D::operator+(const Vector2D& vector) const
        {
            return Vector2D(m_x + vector.m_x, m_y + vector.m_y);
        }

        inline const Vector2D Vector2D::operator*(const float& scale) const
        {
            return Vector2D(scale * m_x, scale * m_y);
        }

        inline const bool Vector2D::operator==(const Vector2D& vector) const
        {
            using SekaiEngine::Math::compareFloat;
            return compareFloat(m_x, vector.m_x) == 0 && compareFloat(m_y, vector.m_y) == 0;
        }

        inline const Vector2 Vector2D::toRaylibVector() const
        {
            return Vector2{m_x, m_y};
        }
        
        inline const float Vector2D::distance()
        {
            return static_cast<const Vector2D&>(*this).distance();
        }

        inline const Vector2D Vector2D::operator+(const Vector2D& vector)
        {
            return static_cast<const Vector2D&>(*this).operator+(vector);
        }

        inline const Vector2D Vector2D::operator*(const float& scale)
        {
            return static_cast<const Vector2D&>(*this).operator*(scale);
        }

        inline const bool Vector2D::operator==(const Vector2D& vector)
        {
            return static_cast<const Vector2D&>(*this).operator==(vector);
        }

        inline const Vector2 Vector2D::toRaylibVector()
        {
            return static_cast<const Vector2D>(*this).toRaylibVector();
        }
    } // namespace Utility
    
} // namespace SekaiEngine


#endif //_SEKAI_ENGINE_UTILITY_VECTOR_2D_H_