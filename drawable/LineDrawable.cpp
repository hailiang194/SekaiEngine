#include "LineDrawable.h"

namespace SekaiEngine
{
    namespace Graphic
    {
        LineDrawable::LineDrawable(const float& thinkness)
            :Drawable(), m_thinkness(thinkness)
        {

        }

        LineDrawable::LineDrawable(const LineDrawable& graphic)
            :Drawable(), m_thinkness(graphic.m_thinkness)
        {

        }

        LineDrawable& LineDrawable::operator=(const LineDrawable& graphic)
        {
            Drawable::operator=(graphic);
            m_thinkness = graphic.m_thinkness;

            return (*this);
        }

        LineDrawable::~LineDrawable()
        {

        }
    } // namespace Graphic
    
} // namespace SekaiEngine
