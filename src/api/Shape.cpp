#include "utility/math.hpp"
#include <cassert>
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

const bool isIntersectLineWithLine(const SekaiEngine::API::Line& l1, const SekaiEngine::API::Line& l2)
{
    assert(true && "Not support yet");
    return false;
}

const bool isIntersectCircleWithPoint(const SekaiEngine::API::Circle& c, const SekaiEngine::API::Point& p)
{
    auto disVector = c.origin() - p.point();
    return SekaiEngine::Utility::cmpFloat(disVector.distance(), c.radius()) <= 0;
}

const bool isIntersectCircleWithLine(const SekaiEngine::API::Circle& c, const SekaiEngine::API::Line& l)
{
    assert(true && "Not support yet");
    return false;
}

const bool isIntersectCircleWithCircle(const SekaiEngine::API::Circle& c1, const SekaiEngine::API::Circle& c2)
{
    auto disVector = c1.origin() - c2.origin();
    return SekaiEngine::Utility::cmpFloat(disVector.distance(), c1.radius() + c2.radius()) <= 0;
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
    
    const Circle* c = dynamic_cast<const Circle*>(&shape);
    if(c != nullptr)
    {
        return isIntersectCircleWithPoint(*c, *this);
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
    
    const Line* l = dynamic_cast<const Line*>(&shape);
    if(l != nullptr)
    {
        return isIntersectLineWithLine(*this, *l);
    }
    
    const Circle* c = dynamic_cast<const Circle*>(&shape);
    if(c != nullptr)
    {
        return isIntersectCircleWithLine(*c, *this);
    }
    return false;
}

SekaiEngine::API::Circle::Circle(const API::Vector2D& origin, const float& radius)
    :Shape(), m_origin(origin), m_radius(radius)
{

}

SekaiEngine::API::Circle::Circle(const Circle& circle)
    :Shape(circle), m_origin(circle.m_origin), m_radius(circle.m_radius)
{

}

SekaiEngine::API::Circle& SekaiEngine::API::Circle::operator=(const Circle& circle)
{
    Shape::operator=(*this);
    m_origin = circle.m_origin;
    m_radius = circle.m_radius;

    return (*this);
}

SekaiEngine::API::Circle::~Circle()
{

}

bool SekaiEngine::API::Circle::intersect(const Shape& shape)
{
    const Point* p = dynamic_cast<const Point*>(&shape);
    if(p != nullptr)
    {
        return isIntersectCircleWithPoint(*this, *p);
    }
    
    const Line* l = dynamic_cast<const Line*>(&shape);
    if(l != nullptr)
    {
        return isIntersectCircleWithLine(*this, *l);
    }

    const Circle* c = dynamic_cast<const Circle*>(&shape);
    if(c != nullptr)
    {
        return isIntersectCircleWithCircle(*this, *c);
    }
    return false;
}
