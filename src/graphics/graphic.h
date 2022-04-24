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
        protected:
            Transform2D m_self;
        };
    } // namespace Graphic
    
} // namespace SekaiEngine


#endif