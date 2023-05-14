#ifndef SEKAI_ENGINE_API_SHAPE_HPP
#define SEKAI_ENGINE_API_SHAPE_HPP

#include "./Vector.hpp"

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

            virtual const bool intersect(const Shape& shape) const = 0;
            const bool intersect(const Shape& shape);
        };

        class Point: public Shape
        {
        public:
            explicit Point(const API::Vector2D& point = API::Vector2D());
            Point(const Point& point);
            Point& operator=(const Point& point);
            Point& operator=(const API::Vector2D& point);
            ~Point();

            const bool intersect(const Shape& shape) const override;

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

            const bool intersect(const Shape& shape) const override;

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

            const bool intersect(const Shape& shape) const override;

            const API::Vector2D& origin() const;
            API::Vector2D& origin();

            const float& radius() const;
            float& radius();

        private:
            API::Vector2D m_origin;
            float m_radius;
        };

        class Rectangle: public Shape
        {
        public:
            Rectangle(const API::Vector2D& position, const float& width, const float& height);
            Rectangle(const Rectangle& rect);
            Rectangle& operator=(const Rectangle& rect);
            ~Rectangle();

            const bool intersect(const Shape& shape) const override;

            const API::Vector2D& position() const;
            API::Vector2D& position();

            const float& width() const;
            float& width();

            const float& height() const;
            float& height();

        private:
            API::Vector2D m_position;
            float m_width;
            float m_height;
        };

        inline const bool Shape::intersect(const Shape& shape)
        {
            return static_cast<const Shape&>(*this).intersect(shape);
        }
        
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

        inline const API::Vector2D& Rectangle::position() const
        {
            return m_position;
        }

        inline API::Vector2D& Rectangle::position()
        {
            return const_cast<API::Vector2D&>(static_cast<const Rectangle&>(*this).position());
        }

        inline const float& Rectangle::width() const
        {
            return m_width;
        }

        inline float& Rectangle::width()
        {
            return const_cast<float&>(static_cast<const Rectangle&>(*this).width());
        }

        inline const float& Rectangle::height() const
        {
            return m_height;
        }

        inline float& Rectangle::height()
        {
            return const_cast<float&>(static_cast<const Rectangle&>(*this).height());
        }
    } // namespace API
    
} // namespace SekaiEngine


#endif //!SEKAI_ENGINE_API_SHAPE_HPP