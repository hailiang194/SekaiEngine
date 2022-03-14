#include "SingleColorDrawable.h"

namespace SekaiEngine
{
    namespace Graphic
    {
        SingleColorDrawable::SingleColorDrawable(const Color& color)
            :Drawable(), m_color(color)
        {

        }

        SingleColorDrawable::SingleColorDrawable(const SingleColorDrawable& graphic)
            :Drawable(graphic), m_color(graphic.m_color)
        {

        }

        SingleColorDrawable& SingleColorDrawable::operator=(const SingleColorDrawable& graphic)
        {
            Drawable::operator=(graphic);

            return (*this);
        }

        SingleColorDrawable::~SingleColorDrawable()
        {

        }
    } // namespace Graphic
    
} // namespace SekaiEngine
