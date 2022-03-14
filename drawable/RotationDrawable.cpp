#include "RotationDrawable.h"

namespace SekaiEngine
{
    namespace Graphic
    {
        RotationDrawable::RotationDrawable(const Vector2& origin, const float& rotation)
            :Drawable(), m_origin(origin), m_rotation(rotation)
        {

        }

        RotationDrawable::RotationDrawable(const RotationDrawable& graphic)
            :Drawable(graphic), m_origin(graphic.m_origin), m_rotation(graphic.m_rotation)
        {

        }

        RotationDrawable& RotationDrawable::operator=(const RotationDrawable& graphic)
        {
            Drawable::operator=(graphic);
            m_origin = graphic.m_origin;
            m_rotation = graphic.m_rotation;

            return (*this);
        }

        RotationDrawable::~RotationDrawable()
        {

        }
    } // namespace Graphic
    
} // namespace SekaiEngine
