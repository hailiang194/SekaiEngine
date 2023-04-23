#include "utility/math.hpp"
#include "./Vector2D.hpp"

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


const SekaiEngine::API::Vector2D SekaiEngine::API::Vector2D::operator+(const Vector2D &vector)
{
    return {m_vector.x + vector.x(), m_vector.y + vector.y()};
}

const SekaiEngine::API::Vector2D SekaiEngine::API::Vector2D::operator*(const float &scale)
{
    return {m_vector.x * scale, m_vector.y * scale};
}

const bool SekaiEngine::API::Vector2D::operator==(const Vector2D& vector)
{
    return (Utility::cmpFloat(m_vector.x, vector.x()) == 0) && (Utility::cmpFloat(m_vector.y, vector.y()) == 0); 
}