#ifndef _SEKAI_ENGINE_DRAWABLE_LINE_H_
    #define _SEKAI_ENGINE_DRAWABLE_LINE_H_

#include "../graphics/drawable.h"

namespace SekaiEngine
{
    namespace Graphic
    {
        class LineDrawable: public Drawable
        {
        public:
            LineDrawable(const float& thinkness);
            LineDrawable(const LineDrawable& graphic);
            LineDrawable& operator=(const LineDrawable& graphic);
            virtual ~LineDrawable();

            virtual void render() = 0;

            const float& thinkness() const;
            float& thinkness();
        protected:
            float m_thinkness;
        };

        inline const float& LineDrawable::thinkness() const
        {
            return m_thinkness;
        }

        inline float& LineDrawable::thinkness()
        {
            return const_cast<float&>(static_cast<const LineDrawable&>(*this).thinkness());
        }
    } // namespace Graphic
    
} // namespace SekaiEngine


#endif //_SEKAI_ENGINE_DRAWABLE_LINE_H_