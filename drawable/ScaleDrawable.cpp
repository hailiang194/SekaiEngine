#include "ScaleDrawable.h"

namespace SekaiEngine
{
    namespace Graphic
    {
        ScaleDrawable::ScaleDrawable(const float& scale)
            :Drawable(), m_scale(scale)
        {

        }

        ScaleDrawable::ScaleDrawable(const ScaleDrawable& graphic)
            :Drawable(graphic), m_scale(graphic.m_scale)
        {

        }

        ScaleDrawable& ScaleDrawable::operator=(const ScaleDrawable& graphic)
        {
            Drawable::operator=(graphic);

            m_scale = graphic.m_scale;

            return (*this);
        }

        ScaleDrawable::~ScaleDrawable()
        {

        }

    } // namespace Graphic
    
} // namespace SekaiEngine
