#ifndef _SEKAI_ENGINE_DRAWABLE_GRADIENT_H_
    #define _SEKAI_ENGINE_DRAWABLE_GRADIENT_H_

#include "raylib.h"
#include "../graphics/drawable.h"

namespace SekaiEngine
{
    namespace Graphic
    {
        class GradientDrawable: public Drawable
        {
        public:
            GradientDrawable(const Color& firstColor, const Color& secondColor);
            GradientDrawable(const GradientDrawable& graphic);
            GradientDrawable& operator=(const GradientDrawable& graphic);
            virtual ~GradientDrawable();

            virtual void render() = 0;

            const Color& firstColor() const;
            Color& firstColor();

            const Color& secondColor() const;
            Color& secondColor();

        protected:
            Color m_firstColor;
            Color m_secondColor;
        };

        const Color& GradientDrawable::firstColor() const
        {
            return m_firstColor;
        }

        Color& GradientDrawable::firstColor()
        {
            return const_cast<Color&>(static_cast<const GradientDrawable&>(*this).firstColor());
        }

        const Color& GradientDrawable::secondColor() const
        {
            return m_secondColor;
        }

        Color& GradientDrawable::secondColor()
        {
            return const_cast<Color&>(static_cast<const GradientDrawable&>(*this).secondColor());
        }
    } // namespace Graphic
    
} // namespace SekaiEngine


#endif //_SEKAI_ENGINE_DRAWABLE_GRADIENT_H_