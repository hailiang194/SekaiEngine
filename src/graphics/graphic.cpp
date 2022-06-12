#include "graphic.h"

namespace SekaiEngine
{
    namespace Graphic
    {
        Graphic::Graphic(const Transform2D& self, Transform2D* parent)
            :m_self(self), m_transformed(self), m_parent(parent)
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

        void Graphic::computeTransform_()
        {
            if(m_parent == nullptr)
                m_transformed = m_self;
            else
                m_transformed = getTransformedValues(*m_parent, m_self);
        }

        void Graphic::update()
        {
            computeTransform_();
        }

        void Graphic::render()
        {
            render_();
        }
    } // namespace Graphic
    
} // namespace SekaiEngine
