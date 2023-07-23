#include "utility/math.hpp"
#include <cassert>
#include "./DrawGraphic.hpp"
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

const bool isIntersectRectWithPoint(const SekaiEngine::API::Rectangle& r, const SekaiEngine::API::Point& p)
{
    if(r.position() == p.point())
    {
        return true;
    }

    auto disVector = p.point() - r.position();
    return 
    (
        SekaiEngine::Utility::cmpFloat(disVector.x(), 0.0f) >= 0 &&
        SekaiEngine::Utility::cmpFloat(disVector.x(), r.width()) <= 0 &&
        SekaiEngine::Utility::cmpFloat(disVector.y(), 0.0f) >= 0 &&
        SekaiEngine::Utility::cmpFloat(disVector.y(), r.height()) <= 0
    );
}

bool LiangBarsky (double edgeLeft, double edgeRight, double edgeBottom, double edgeTop,   // Define the x/y clipping values for the border.
                  double x0src, double y0src, double x1src, double y1src,                 // Define the start and end points of the line.
                  double &x0clip, double &y0clip, double &x1clip, double &y1clip)         // The output values, so declare these outside.
{
    //ref: https://www.skytopia.com/project/articles/compsci/clipping.html
    double t0 = 0.0;    double t1 = 1.0;
    double xdelta = x1src-x0src;
    double ydelta = y1src-y0src;
    double p,q,r;

    for(int edge=0; edge<4; edge++) {   // Traverse through left, right, bottom, top edges.
        if (edge==0) {  p = -xdelta;    q = -(edgeLeft-x0src);  }
        if (edge==1) {  p = xdelta;     q =  (edgeRight-x0src); }
        if (edge==2) {  p = -ydelta;    q = -(edgeBottom-y0src);}
        if (edge==3) {  p = ydelta;     q =  (edgeTop-y0src);   }   
        r = q/p;
        if(p==0 && q<0) return false;   // Don't draw line at all. (parallel line outside)

        if(p<0) {
            if(r>t1) return false;         // Don't draw line at all.
            else if(r>t0) t0=r;            // Line is clipped!
        } else if(p>0) {
            if(r<t0) return false;      // Don't draw line at all.
            else if(r<t1) t1=r;         // Line is clipped!
        }
    }

    x0clip = x0src + t0*xdelta;
    y0clip = y0src + t0*ydelta;
    x1clip = x0src + t1*xdelta;
    y1clip = y0src + t1*ydelta;

    return true;        // (clipped) line is drawn
}



const bool isIntersectRectWithLine(const SekaiEngine::API::Rectangle& r, const SekaiEngine::API::Line& l)
{
    double x1 = 0; 
    double y1 = 0; 
    double x2 = 0;
    double y2 = 0;

    return LiangBarsky(static_cast<double>(r.position().x()), static_cast<double>(r.position().x() + r.width()), 
    static_cast<double>(r.position().y() + r.height()), static_cast<double>(r.position().y()),
    static_cast<double>(l.first().x()), static_cast<double>(l.first().y()), 
    static_cast<double>(l.second().x()), static_cast<double>(l.second().y()),
    x1, y1, x2, y2
    );
}

const bool isIntersectRectWithCircle(const SekaiEngine::API::Rectangle& r, const SekaiEngine::API::Circle& c)
{
    //ref: https://yal.cc/rectangle-circle-intersection-test/

    // find the point of rectangle that is the closest to the circle' center
    float closestX = c.origin().x();
    float closestY = c.origin().y();

    if(SekaiEngine::Utility::cmpFloat(closestX, r.position().x()) < 0)
    {
        closestX = r.position().x();
    }
    else if(SekaiEngine::Utility::cmpFloat(closestX, r.position().x() + r.width()) > 0)
    {
        closestX = r.position().x() + r.width();
    }

    if(SekaiEngine::Utility::cmpFloat(closestY, r.position().y()) < 0)
    {
        closestY = r.position().y();
    }
    else if(SekaiEngine::Utility::cmpFloat(closestY, r.position().y() + r.height()) > 0)
    {
        closestY = r.position().y() + r.height();
    }
    return isIntersectCircleWithPoint(c, SekaiEngine::API::Point({closestX, closestY}));
}

const bool isIntersectRectWithRect(const SekaiEngine::API::Rectangle& r1, const SekaiEngine::API::Rectangle& r2)
{
    //ref: http://jeffreythompson.org/collision-detection/rect-rect.php
    return 
    (
        SekaiEngine::Utility::cmpFloat(r1.position().x() + r1.width(), r2.position().x()) >= 0 &&
        SekaiEngine::Utility::cmpFloat(r1.position().x(), r2.width() + r2.position().x()) <= 0 &&
        SekaiEngine::Utility::cmpFloat(r1.position().y() + r1.height(), r2.position().y()) >= 0 &&
        SekaiEngine::Utility::cmpFloat(r1.position().y(), r2.width() + r2.position().y()) <= 0
    );
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

const bool SekaiEngine::API::Point::intersect(const Shape& shape) const
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

    const Rectangle* r = dynamic_cast<const Rectangle*>(&shape);
    if(r != nullptr)
    {
        return isIntersectRectWithPoint(*r, *this);
    }
    return false;
}

#define RELATIVE_POINT(point) { \
        properties.offset().x() + (point).x() * properties.scale().x(), \
        properties.offset().y() + (point).y() * properties.scale().y() \
    }

const bool SekaiEngine::API::Point::isRenderable(const Renderable::RenderableProperties& properties, const Shape& shape) const
{
    API::Vector2D relativePosition = RELATIVE_POINT(this->point());
    return shape.intersect((Point)relativePosition);
}

void SekaiEngine::API::Point::render(const Renderable::RenderableProperties properties)
{
    API::Vector2D relativePosition = RELATIVE_POINT(this->point());
    API::drawPoint((Point)relativePosition, properties.color());
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

const bool SekaiEngine::API::Line::intersect(const Shape& shape) const
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

    const Rectangle* r = dynamic_cast<const Rectangle*>(&shape);
    if(r != nullptr)
    {
        return isIntersectRectWithLine(*r, *this);
    }
    return false;
}

const bool SekaiEngine::API::Line::isRenderable(const Renderable::RenderableProperties& properties, const Shape& shape) const
{
    API::Vector2D firstRelative = RELATIVE_POINT(this->first());
    API::Vector2D secondRelative = RELATIVE_POINT(this->second());
    return shape.intersect(API::Line(firstRelative, secondRelative));
}

void SekaiEngine::API::Line::render(const Renderable::RenderableProperties properties)
{
    API::Vector2D firstRelative = RELATIVE_POINT(this->first());
    API::Vector2D secondRelative = RELATIVE_POINT(this->second());
    API::drawLine(API::Line(firstRelative, secondRelative), properties.color(), properties.thick() == FILL_THICK ? 1.0f : properties.thick());
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

const bool SekaiEngine::API::Circle::intersect(const Shape& shape) const
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

    const Rectangle* r = dynamic_cast<const Rectangle*>(&shape);
    if(r != nullptr)
    {
        return isIntersectRectWithCircle(*r, *this);
    }
    return false;
}

const bool SekaiEngine::API::Circle::isRenderable(const Renderable::RenderableProperties& properties, const Shape& shape) const
{
    API::Vector2D relativeOrigin = RELATIVE_POINT(this->origin());
    float relativeRadius = this->radius() * properties.scale().x();
    return shape.intersect(API::Circle(relativeOrigin, relativeRadius));
}

void SekaiEngine::API::Circle::render(const Renderable::RenderableProperties properties)
{
    API::Vector2D relativeOrigin = RELATIVE_POINT(this->origin());
    float relativeRadius = this->radius() * properties.scale().x();
    if(properties.thick() == FILL_THICK || Utility::cmpFloat(relativeRadius, properties.thick()) <= 0)
    {
        API::drawCircle(API::Circle(relativeOrigin, relativeRadius), properties.color(),
        properties.segments(), properties.startAngle(), properties.endAngle());
    }
    else
    {
        API::drawRing(relativeOrigin, relativeRadius, relativeRadius - properties.thick(), properties.color(), properties.segments(),
        properties.startAngle(), properties.endAngle());
    }
}

SekaiEngine::API::Rectangle::Rectangle(const API::Vector2D& position, const float& width, const float& height)
    :Shape(), m_position(position), m_width(width), m_height(height)
{

}

SekaiEngine::API::Rectangle::Rectangle(const Rectangle& rect)
    :Shape(), m_position(rect.m_position), m_width(rect.m_width), m_height(rect.m_height)
{

}

SekaiEngine::API::Rectangle& SekaiEngine::API::Rectangle::operator=(const Rectangle& rect)
{
    Shape::operator=(rect);
    m_position = rect.m_position;
    m_width = rect.m_width;
    m_height = rect.m_height;

    return (*this);
}

SekaiEngine::API::Rectangle::~Rectangle()
{

}

const bool SekaiEngine::API::Rectangle::intersect(const Shape& shape) const
{
    const Point* p = dynamic_cast<const Point*>(&shape);
    if(p != nullptr)
    {
        return isIntersectRectWithPoint(*this, *p);
    }

    const Line* l = dynamic_cast<const Line*>(&shape);
    if(l != nullptr)
    {
        return isIntersectRectWithLine(*this, *l);
    }

    const Circle* c = dynamic_cast<const Circle*>(&shape);
    if(c != nullptr)
    {
        return isIntersectRectWithCircle(*this, *c);
    }

    const Rectangle* r = dynamic_cast<const Rectangle*>(&shape);
    if(r != nullptr)
    {
        return isIntersectRectWithRect(*this, *r);
    }
    return false;
}

const bool SekaiEngine::API::Rectangle::isRenderable(const Renderable::RenderableProperties& properties, const Shape& shape) const
{
    API::Vector2D relativePostion = RELATIVE_POINT(this->position());
    float relativeWith = this->width() * properties.scale().x();
    float relativeHeight = this->height() * properties.scale().y();
    return shape.intersect(API::Rectangle(relativePostion, relativeWith, relativeHeight));
}

void SekaiEngine::API::Rectangle::render(const Renderable::RenderableProperties properties)
{
    API::Vector2D relativePostion = RELATIVE_POINT(this->position());
    float relativeWith = this->width() * properties.scale().x();
    float relativeHeight = this->height() * properties.scale().y();
    API::drawRectangle(API::Rectangle(relativePostion, relativeWith, relativeHeight), properties.color());
}