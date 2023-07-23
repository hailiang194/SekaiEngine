#ifndef SEKAI_ENGINE_API_DRAW_GRAPHIC_HPP
#define SEKAI_ENGINE_API_DRAW_GRAPHIC_HPP

#include "./Shape.hpp"
#include "./Color.hpp"

namespace SekaiEngine
{
    namespace API
    {
        /// @brief draw the bouding area as a red rectangle with the thickness is 2px
        /// @param bouding bounding area
        void drawBounding(const API::Rectangle& bouding);

        /// @brief Draw point, basicly mean change the color of pixel
        /// @param point draw point
        /// @param color color
        void drawPoint(const API::Point& point, const API::Color& color);

        /// @brief draw line
        /// @param line draw line
        /// @param color color
        /// @param thickness thicknees
        void drawLine(const API::Line& line, const API::Color& color, const float& thickness);

        /// @brief Draw Circle with segments and sector
        /// @param circle draw circle
        /// @param color color
        /// @param segments segments
        /// @param startAngle start angle in degree (if you want to draw circle add it as 0)
        /// @param endAngle end angle in degree (if you want to draw circle add it as 360)
        void drawCircle(const API::Circle& circle, const API::Color& color, const int segments, float startAngle, float endAngle);

        /// @brief Draw Ring with segment and sector
        /// @param origin ring origin
        /// @param outerRadius outer radius
        /// @param innerRadius inner radius
        /// @param color color
        /// @param segments segments
        /// @param startAngle start angle in degree (if you want to draw circle add it as 0)
        /// @param endAngle end angle in degree (if you want to draw circle add it as 360)
        void drawRing(const API::Vector2D& origin, const float& outerRadius, const float& innerRadius,
            const API::Color& color, const int segments, float startAngle, float endAngle);

        /// @brief Draw rectangle
        /// @param rect draw rectangle
        /// @param color color
        void drawRectangle(const API::Rectangle& rect, const API::Color& color);
    } // namespace API
    
} // namespace SekaiEngine


#endif //!SEKAI_ENGINE_API_DRAW_GRAPHIC_HPP