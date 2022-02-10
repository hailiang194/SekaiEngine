#ifndef SEKAI_ENGINE_GRAPHIC_SHAPE_H_
    #define SEKAI_ENGINE_GRAPHIC_SHAPE_H_

#include "../objects/game_object.h"

//When you have new shape please write the flag here
#define RECTANGLE_SHAPE (1 << 3)
#define CIRCLE_SHAPE    (1 << 2)
#define LINE_SHAPE      (1 << 1)
#define POINT_SHAPE     (1 << 0)
#define UNDEFINED_SHAPE 0

namespace SekaiEngine
{
    namespace Graphic
    {
        typedef unsigned int ShapeFlag;
        class Shape: public SekaiEngine::Object::GameObject
        {
        public:
            Shape(const ShapeFlag& SHAPE_FLAG = UNDEFINED_SHAPE);
            Shape(const Shape& shape);
            Shape& operator=(const Shape& shape);
            virtual ~Shape();

            virtual void setup();

            virtual void update();

            virtual void draw();

            virtual void kill();

            const ShapeFlag& SHAPE_FLAG() const;
            const ShapeFlag& SHAPE_FLAG();

        protected:
            const ShapeFlag m_SHAPE_FLAG;
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