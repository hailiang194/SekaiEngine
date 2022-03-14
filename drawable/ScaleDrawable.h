#ifndef _SEKAI_ENGINE_DRAWABLE_SCALE_H_
    #define _SEKAI_ENGINE_DRAWABLE_SCALE_H_

#include "../graphics/drawable.h"

namespace SekaiEngine
{
    namespace Graphic
    {
        class ScaleDrawable: public Drawable
        {
        public:
            ScaleDrawable(const float& scale);
            ScaleDrawable(const ScaleDrawable& graphic);
            ScaleDrawable& operator=(const ScaleDrawable& graphic);
            virtual ~ScaleDrawable();

            virtual void render() = 0;

            const float& scale() const;
            float& scale();

        protected:
            float m_scale;
        };

        const float& ScaleDrawable::scale() const
        {
            return m_scale;
        }

        float& ScaleDrawable::scale()
        {
            return const_cast<float&>(static_cast<const ScaleDrawable&>(*this).scale());
        }
    } // namespace Graphic
    
} // namespace SekaiEngine


#endif //_SEKAI_ENGINE_DRAWABLE_SCALE_H_