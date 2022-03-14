#ifndef _SEKAI_ENGINE_DRAWABLE_SINGLE_COLOR_H_
    #define _SEKAI_ENGINE_DRAWABLE_SINGLE_COLOR_H_

#include "raylib.h"
#include "../graphics/drawable.h"

namespace SekaiEngine
{
    namespace Graphic
    {
        class SingleColorDrawable: public Drawable
        {
        public:
            SingleColorDrawable(const Color& color);
            SingleColorDrawable(const SingleColorDrawable& graphic);
            SingleColorDrawable& operator=(const SingleColorDrawable& graphic);
            virtual ~SingleColorDrawable();

            virtual void render() = 0;

            const Color& color() const;
            Color& color();
        protected:
            Color m_color;
        };

        inline const Color& SingleColorDrawable::color() const
        {
            return m_color;
        }

        inline Color& SingleColorDrawable::color()
        {
            return const_cast<Color&>(static_cast<const SingleColorDrawable&>(*this).color());
        }
    } // namespace Graphic
    
} // namespace SekaiEngine


#endif //_SEKAI_ENGINE_DRAWABLE_SINGLE_COLOR_H_