#ifndef _SEKAI_ENGINE_DRAWABLE_ROTATION_H_
    #define _SEKAI_ENGINE_DRAWABLE_ROTATION_H_

#include "raylib.h"
#include "../graphics/drawable.h"

namespace SekaiEngine
{
    namespace Graphic
    {
        class RotationDrawable: public Drawable
        {
        public:
            RotationDrawable(const Vector2& origin, const float& rotation);
            RotationDrawable(const RotationDrawable& graphic);
            RotationDrawable& operator=(const RotationDrawable& graphic);
            virtual ~RotationDrawable();

            virtual void render() = 0;

            const Vector2& origin() const;
            Vector2& origin();

            const float& rotation() const;
            float& rotation();

        protected:
            Vector2 m_origin;
            float m_rotation;
        };

        const Vector2& RotationDrawable::origin() const
        {
            return m_origin;
        }

        Vector2& RotationDrawable::origin()
        {
            return const_cast<Vector2&>(static_cast<const RotationDrawable&>(*this).origin());
        }

        const float& RotationDrawable::rotation() const
        {
            return m_rotation;
        }

        float& RotationDrawable::rotation()
        {
            return const_cast<float&>(static_cast<const RotationDrawable&>(*this).rotation());
        }
    } // namespace Graphic
    
} // namespace SekaiEngine


#endif //_SEKAI_ENGINE_DRAWABLE_ROTATION_H_