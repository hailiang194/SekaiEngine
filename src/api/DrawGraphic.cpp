#include "./DrawGraphic.hpp"

void SekaiEngine::API::drawBounding(const API::Rectangle& bouding)
{
#ifdef RAYLIB_API
    ::Rectangle rect = {
            bouding.position().x(),
            bouding.position().y(),
            bouding.width(),
            bouding.height()
    };
    ::Color color = {230, 41, 55, 255};
    DrawRectangleLinesEx(rect, 2, color);
#else
#endif
}

void SekaiEngine::API::drawPoint(const API::Point& point, const API::Color& color)
{
#ifdef RAYLIB_API
    DrawPixel(point.point().x(), point.point().y(), color.get());
#else
#endif 
}

void SekaiEngine::API::drawLine(const API::Line& line, const API::Color& color, const float& thickness)
{
#ifdef RAYLIB_API
    DrawLineEx(line.first().get(), line.second().get(), thick, color.get());
#else
#endif
}

void SekaiEngine::API::drawCircle(const API::Circle& circle, const API::Color& color, const int segments, float startAngle, float endAngle)
{
#ifdef RAYLIB_API
    DrawCircleSector(circle.origin().get(), circle.radius(), startAngle, endAngle, segments, color.get());
#else
#endif
}

void SekaiEngine::API::drawRing(const API::Vector2D& origin, const float& outerRadius, const float& innerRadius, const API::Color& color, 
    const int segments, float startAngle, float endAngle)
{
#ifdef RAYLIB_API
    DrawRingLines(origin.get(), innerRadius, outerRadius, startAngle, endAngle, segments, color.get());
#else
#endif
}

void SekaiEngine::API::drawRectangle(const API::Rectangle& rect, const API::Color& color)
{
#ifdef RAYLIB_API
    DrawRectangle(rect.position().x(), rect.position().y(), rect.width(), rect.height(), color.get());
#else
#endif
}