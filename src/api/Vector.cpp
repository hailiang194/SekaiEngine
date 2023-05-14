#include "utility/math.hpp"
#include "./Vector.hpp"

SekaiEngine::API::Vector2D::Vector2D(const float &x, const float &y)
    :m_vector({x, y})
{

}

SekaiEngine::API::Vector2D::Vector2D(const ::Vector2 &vector)
    :m_vector(vector)
{

}

SekaiEngine::API::Vector2D::Vector2D(const Vector2D &vector)
    :m_vector(vector.m_vector)
{

}

SekaiEngine::API::Vector2D& SekaiEngine::API::Vector2D::operator=(const Vector2D &vector)
{
    m_vector = vector.m_vector;
    return (*this);
}

SekaiEngine::API::Vector2D &SekaiEngine::API::Vector2D::operator=(const ::Vector2 &vector)
{
    m_vector = vector;
    return (*this);
}

SekaiEngine::API::Vector2D::~Vector2D()
{

}


const SekaiEngine::API::Vector2D SekaiEngine::API::Vector2D::operator+(const Vector2D &vector) const
{
    return {m_vector.x + vector.x(), m_vector.y + vector.y()};
}

const SekaiEngine::API::Vector2D SekaiEngine::API::Vector2D::operator+(const Vector2D &vector)
{
    return const_cast<const Vector2D&>(*this).operator+(vector);
}

const SekaiEngine::API::Vector2D SekaiEngine::API::Vector2D::operator-(const Vector2D &vector) const
{
    return {m_vector.x - vector.x(), m_vector.y - vector.y()};
}

const SekaiEngine::API::Vector2D SekaiEngine::API::Vector2D::operator-(const Vector2D &vector) 
{
    return const_cast<const Vector2D&>(*this).operator-(vector);
}

const SekaiEngine::API::Vector2D SekaiEngine::API::Vector2D::operator*(const float &scale) const
{
    return {m_vector.x * scale, m_vector.y * scale};
}

const SekaiEngine::API::Vector2D SekaiEngine::API::Vector2D::operator*(const float &scale)
{
    return const_cast<const Vector2D&>(*this).operator*(scale);
}

const bool SekaiEngine::API::Vector2D::operator==(const Vector2D& vector) const
{
    return (Utility::cmpFloat(m_vector.x, vector.x()) == 0) && (Utility::cmpFloat(m_vector.y, vector.y()) == 0); 
}

const bool SekaiEngine::API::Vector2D::operator==(const Vector2D& vector)
{
    return const_cast<const Vector2D&>(*this).operator==(vector);
}

const float SekaiEngine::API::Vector2D::dot(const Vector2D& vector) const
{
    return m_vector.x * vector.x() + m_vector.y * vector.y();
}

const float SekaiEngine::API::Vector2D::dot(const Vector2D& vector) 
{
    return const_cast<const Vector2D&>(*this).dot(vector);
}

const float SekaiEngine::API::Vector2D::distance() const
{
    return static_cast<const float>(std::sqrt(static_cast<double>(m_vector.x * m_vector.x + m_vector.y * m_vector.y)));
}

const float SekaiEngine::API::Vector2D::distance() 
{
    return const_cast<const Vector2D&>(*this).distance();
}