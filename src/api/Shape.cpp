#include "utility/math.hpp"
#include "./Shape.hpp"

const bool isIntersectPointWithPoint(const SekaiEngine::API::Point& p1, const SekaiEngine::API::Point& p2)
{
    return p1.point() == p2.point();
}

const bool isIntersectLineWithPoint(const SekaiEngine::API::Line& l, const SekaiEngine::API::Point& p)
{
    auto deltaPoint = p.point() - l.first();
    auto deltaLine = l.second() - l.first();

    return 
        SekaiEngine::Utility::cmpFloat(deltaPoint.dot(deltaLine), deltaPoint.distance() * deltaLine.distance()) == 0 &&
        SekaiEngine::Utility::cmpFloat(deltaPoint.x(), deltaLine.x()) <= 0;
    ;
}

SekaiEngine::API::Shape::Shape()
{

}

SekaiEngine::API::Shape::Shape(const Shape& shape)
{

}
SekaiEngine::API::Shape& SekaiEngine::API::Shape::operator=(const Shape& shape)
{
    return (*this);
}

SekaiEngine::API::Shape::~Shape()
{

}

SekaiEngine::API::Point::Point(const API::Vector2D& point)
    :Shape(), m_point(point)
{

}

SekaiEngine::API::Point::Point(const SekaiEngine::API::Point& point)
    :Shape(point), m_point(point.m_point)
{
    
}

SekaiEngine::API::Point& SekaiEngine::API::Point::operator=(const Point& point)
{
    Shape::operator=(point);
    m_point = point.m_point;
    return (*this);
}

SekaiEngine::API::Point& SekaiEngine::API::Point::operator=(const API::Vector2D& point)
{   
    m_point = point;
    return (*this);
}

SekaiEngine::API::Point::~Point()
{

}

bool SekaiEngine::API::Point::intersect(const Shape& shape)
{
    const Point* p = dynamic_cast<const Point*>(&shape); 
    if(p != nullptr)
    {
        return isIntersectPointWithPoint(*this, *p);
    }

    const Line* l = dynamic_cast<const Line*>(&shape);
    if(l != nullptr)
    {
        return isIntersectLineWithPoint(*l, *this);
    }
    return false;
}

SekaiEngine::API::Line::Line(const API::Vector2D& first, const API::Vector2D& second)
    :Shape(), m_first(first), m_second(second)
{

}

SekaiEngine::API::Line::Line(const Line& line)
    :Shape(line), m_first(line.m_first), m_second(line.m_second)
{

}

SekaiEngine::API::Line& SekaiEngine::API::Line::operator=(const Line& line)
{
    Shape::operator=(line);
    m_first = line.m_first;
    m_second = line.m_second;
    
    return (*this);
}

SekaiEngine::API::Line::~Line()
{

}

bool SekaiEngine::API::Line::intersect(const Shape& shape)
{
    const Point* p = dynamic_cast<const Point*>(&shape); 
    if(p != nullptr)
    {
        return isIntersectLineWithPoint(*this, *p);
    }
    return false;
}
