#ifndef _SEKAI_ENGINE_GRAPHIC_H_
    #define _SEKAI_ENGINE_GRAPHIC_H_

#include "transform2d.h"

namespace SekaiEngine
{
    namespace Graphic
    {
        class Graphic
        {
        public:
            Graphic(const Transform2D& self = Transform2D());
            Graphic(const Graphic& graphic);
            Graphic& operator=(const Graphic& graphic);
            virtual ~Graphic();

            //Draw graphic based on parent transform and return the transformed value
            virtual const Transform2D drawGraphic(const Transform2D* parent = nullptr) = 0;

            const Transform2D& transform() const;
            Transform2D& transform();
        protected:
            Transform2D m_self;
        };

        inline const Transform2D& Graphic::transform() const
        {
            return m_self;
        }

        inline Transform2D& Graphic::transform()
        {
            return const_cast<Transform2D&>(static_cast<const Graphic&>(*this).transform());
        }
    } // namespace Graphic
    
} // namespace SekaiEngine


#endif