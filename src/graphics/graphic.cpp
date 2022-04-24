#include "graphic.h"

namespace SekaiEngine
{
    namespace Graphic
    {
        Graphic::Graphic(const Transform2D& self)
            :m_self(self)
        {

        }

        Graphic::Graphic(const Graphic& graphic)
            :m_self(graphic.m_self)
        {

        }

        Graphic& Graphic::operator=(const Graphic& graphic)
        {
            m_self = graphic.m_self;
            return (*this);
        }

        Graphic::~Graphic()
        {

        }
    } // namespace Graphic
    
} // namespace SekaiEngine
