#include "GradientDrawable.h"

namespace SekaiEngine
{
    namespace Graphic
    {
        GradientDrawable::GradientDrawable(const Color& firstColor, const Color& secondColor)
            :Drawable(), m_firstColor(firstColor), m_secondColor(secondColor)
        {

        }

        GradientDrawable::GradientDrawable(const GradientDrawable& graphic)
            :Drawable(graphic), m_firstColor(graphic.m_firstColor), m_secondColor(graphic.m_secondColor)
        {

        }

        GradientDrawable& GradientDrawable::operator=(const GradientDrawable& graphic)
        {
            Drawable::operator=(graphic);

            m_firstColor = graphic.m_firstColor;
            m_secondColor = graphic.m_secondColor;

            return (*this);
        }

        GradientDrawable::~GradientDrawable()
        {

        }
    } // namespace Graphic
    
} // namespace SekaiEngine
