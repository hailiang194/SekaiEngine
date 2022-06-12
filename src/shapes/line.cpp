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

        void Line::computeTransform_()
        {
            Shape::computeTransform_();
        }

        void Line::render_()
        {
            Utility::Vector2D tfEndPoint = (m_endPoint + m_self.position() * -1) * m_transformed.scale() + m_transformed.position();

            DrawLineV(m_transformed.position().toRaylibVector(), tfEndPoint.toRaylibVector(), m_transformed.color());
        }
    } // namespace Graphic
    
} // namespace SekaiEngine
