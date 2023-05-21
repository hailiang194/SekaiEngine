#include "utility/math.hpp"
#include "./Vector.hpp"

#ifdef RAYLIB_API
#define RAW_TO_VECTOR(vec) m_x = vec.x; m_y = vec.y;
#else

#endif

SekaiEngine::API::Vector2D::Vector2D(const float &x, const float &y)
    :m_x(x), m_y(y)
{

}

SekaiEngine::API::Vector2D::Vector2D(const VECTOR2_API &vector)
{
    RAW_TO_VECTOR(vector)
}

SekaiEngine::API::Vector2D::Vector2D(const Vector2D &vector)
    :m_x(vector.m_x), m_y(vector.m_y)
{

}

SekaiEngine::API::Vector2D& SekaiEngine::API::Vector2D::operator=(const Vector2D &vector)
{
    m_x = vector.m_x;
    m_y = vector.m_y;
    return (*this);
}

SekaiEngine::API::Vector2D &SekaiEngine::API::Vector2D::operator=(const VECTOR2_API &vector)
{
    RAW_TO_VECTOR(vector)
    return (*this);
}

SekaiEngine::API::Vector2D::~Vector2D()
{

}


const SekaiEngine::API::Vector2D SekaiEngine::API::Vector2D::operator+(const Vector2D &vector) const
{
    return {m_x + vector.x(), m_y + vector.y()};
}

const SekaiEngine::API::Vector2D SekaiEngine::API::Vector2D::operator+(const Vector2D &vector)
{
    return const_cast<const Vector2D&>(*this).operator+(vector);
}

const SekaiEngine::API::Vector2D SekaiEngine::API::Vector2D::operator-(const Vector2D &vector) const
{
    return {m_x - vector.x(), m_y - vector.y()};
}

const SekaiEngine::API::Vector2D SekaiEngine::API::Vector2D::operator-(const Vector2D &vector) 
{
    return const_cast<const Vector2D&>(*this).operator-(vector);
}

const SekaiEngine::API::Vector2D SekaiEngine::API::Vector2D::operator*(const float &scale) const
{
    return {m_x * scale, m_y * scale};
}

const SekaiEngine::API::Vector2D SekaiEngine::API::Vector2D::operator*(const float &scale)
{
    return const_cast<const Vector2D&>(*this).operator*(scale);
}

const bool SekaiEngine::API::Vector2D::operator==(const Vector2D& vector) const
{
    return (Utility::cmpFloat(m_x, vector.x()) == 0) && (Utility::cmpFloat(m_y, vector.y()) == 0); 
}

const bool SekaiEngine::API::Vector2D::operator==(const Vector2D& vector)
{
    return const_cast<const Vector2D&>(*this).operator==(vector);
}

const float SekaiEngine::API::Vector2D::dot(const Vector2D& vector) const
{
    return m_x * vector.x() + m_y * vector.y();
}

const float SekaiEngine::API::Vector2D::dot(const Vector2D& vector) 
{
    return const_cast<const Vector2D&>(*this).dot(vector);
}

const float SekaiEngine::API::Vector2D::distance() const
{
    return static_cast<const float>(std::sqrt(static_cast<double>(m_x * m_x + m_y * m_y)));
}

const float SekaiEngine::API::Vector2D::distance() 
{
    return const_cast<const Vector2D&>(*this).distance();
}