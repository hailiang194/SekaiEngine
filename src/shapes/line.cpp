#include "line.h"

namespace SekaiEngine
{
    namespace Graphic
    {
        Line::Line(const Utility::Vector2D& startPoint, const Utility::Vector2D& endPoint)
            :Shape(LINE_SHAPE), m_endPoint(endPoint)
        {
            m_self.position() = startPoint;
        }

        Line::Line(const Line& line)
            :Shape(line), m_endPoint(line.m_endPoint)
        {

        }

        Line& Line::operator=(const Line& line)
        {
            Shape::operator=(line);
            m_endPoint = line.m_endPoint;

            return (*this);
        }

        Line::~Line()
        {

        }

        const Transform2D Line::drawGraphic(const Transform2D* parent)
        {
            Transform2D transformed = (parent == nullptr) ? m_self : getTransformedValues(*parent, m_self);

            Utility::Vector2D tfEndPoint = (m_endPoint + m_self.position() * -1) * m_self.scale() + m_self.position();

            DrawLineV(m_self.position().toRaylibVector(), tfEndPoint.toRaylibVector(), m_self.color());

            return transformed;
        }
    } // namespace Graphic
    
} // namespace SekaiEngine
