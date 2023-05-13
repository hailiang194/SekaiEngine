#ifndef SEKAI_ENGINE_API_SHAPE_HPP
#define SEKAI_ENGINE_API_SHAPE_HPP

#include "./Vector2D.hpp"

namespace SekaiEngine
{
    namespace API
    {
        class Shape
        {
        public:
            Shape();
            Shape(const Shape& shape);
            Shape& operator=(const Shape& shape);
            virtual ~Shape();

            virtual bool intersect(const Shape& shape) = 0;
        };

        class Point: public Shape
        {
        public:
            explicit Point(const API::Vector2D& point = API::Vector2D());
            Point(const Point& point);
            Point& operator=(const Point& point);
            Point& operator=(const API::Vector2D& point);
            ~Point();

            bool intersect(const Shape& shape) override;

            const API::Vector2D& point() const;
            API::Vector2D& point();
        private:
            API::Vector2D m_point;
        };

        class Line: public Shape
        {
        public:
            Line(const API::Vector2D& first, const API::Vector2D& second);
            Line(const Line& line);
            Line& operator=(const Line& line);
            ~Line();

            bool intersect(const Shape& shape) override;

            const API::Vector2D& first() const;
            API::Vector2D& first();

            const API::Vector2D& second() const;
            API::Vector2D& second();
        private:
            API::Vector2D m_first;
            API::Vector2D m_second;
        };

        class Circle: public Shape
        {
        public:
            Circle(const API::Vector2D& origin, const float& radius);
            Circle(const Circle& circle);
            Circle& operator=(const Circle& circle);
            ~Circle();

            bool intersect(const Shape& shape) override;

            const API::Vector2D& origin() const;
            API::Vector2D& origin();

            const float& radius() const;
            float& radius();

        private:
            API::Vector2D m_origin;
            float m_radius;
        };
        
        inline const API::Vector2D& Point::point() const
        {
            return m_point;
        }

        inline API::Vector2D& Point::point()
        {
            return const_cast<API::Vector2D&>(static_cast<const Point&>(*this).point());
        }

        inline const API::Vector2D& Line::first() const
        {
            return m_first;
        }

        inline API::Vector2D& Line::first()
        {
            return const_cast<API::Vector2D&>(static_cast<const Line&>(*this).first());
        }

        inline const API::Vector2D& Line::second() const
        {
            return m_second;
        }

        inline API::Vector2D& Line::second()
        {
            return const_cast<API::Vector2D&>(static_cast<const Line&>(*this).second());
        }

        inline const API::Vector2D& Circle::origin() const
        {
            return m_origin;
        }

        inline API::Vector2D& Circle::origin()
        {
            return const_cast<API::Vector2D&>(static_cast<const Circle&>(*this).origin());
        }

        inline const float& Circle::radius() const
        {
            return m_radius;
        }

        inline float& Circle::radius()
        {
            return const_cast<float&>(static_cast<const Circle&>(*this).radius());
        }
    } // namespace API
    
} // namespace SekaiEngine


#endif //!SEKAI_ENGINE_API_SHAPE_HPP