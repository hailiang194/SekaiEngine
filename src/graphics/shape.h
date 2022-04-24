#ifndef SEKAI_ENGINE_GRAPHIC_SHAPE_H_
    #define SEKAI_ENGINE_GRAPHIC_SHAPE_H_

#include "graphic.h"

//When you have new shape please write the flag here
#define RECTANGLE_SHAPE 0x8
#define CIRCLE_SHAPE    0x4
#define LINE_SHAPE      0x2
#define POINT_SHAPE     0x1
#define UNDEFINED_SHAPE 0x0

namespace SekaiEngine
{
    namespace Graphic
    {
        typedef unsigned int ShapeFlag;
        class Shape: public Graphic
        {
        public:
            Shape(const ShapeFlag& SHAPE_FLAG, const Transform2D& self = Transform2D());
            Shape(const Shape& shape);
            Shape& operator=(const Shape& shape);
            virtual ~Shape();

            const ShapeFlag& SHAPE_FLAG() const;
            const ShapeFlag& SHAPE_FLAG();
            
            virtual const Transform2D drawGraphic(const Transform2D* parent = nullptr) = 0;

        protected:
            ShapeFlag m_SHAPE_FLAG;
        };

        inline const ShapeFlag& Shape::SHAPE_FLAG() const
        {
            return m_SHAPE_FLAG;
        }

        inline const ShapeFlag& Shape::SHAPE_FLAG()
        {
            return static_cast<const Shape&>(*this).SHAPE_FLAG();
        }
    } // namespace Graphic
    
} // namespace SekaiEngine


#endif