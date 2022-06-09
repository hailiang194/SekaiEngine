#include "input-axis.h"

namespace SekaiEngine
{
    namespace Input
    {
        InputAxis::InputAxis(const float &adjust, const float &value)
            : m_adjust(adjust), m_value(value)
        {
        }

        InputAxis::InputAxis(const InputAxis &axis)
            : m_adjust(axis.m_adjust), m_value(axis.m_value)
        {
        }

        InputAxis &InputAxis::operator=(const InputAxis &axis)
        {
            m_adjust = axis.m_adjust;
            m_value = axis.m_value;
            return (*this);
        }

        InputAxis::~InputAxis()
        {
        }

        void InputAxis::update()
        {
            if (increase())
            {
                m_value = Math::compareFloat(m_value + m_adjust, 1.0f) >= 0 ? 1.0f : m_value + m_adjust;
            }
            else if (decrease())
            {
                m_value = Math::compareFloat(m_value - m_adjust, -1.0f) <= 0 ? -1.0f : m_value - m_adjust;
            }
            else
            {
                m_value = 0.0f;
            }
        }


        KeyboardInputAxis::KeyboardInputAxis(const int& increaseKey, const int& decreaseKey, const float& adjust, const float& value)
            :InputAxis(adjust, value), m_increaseKey(increaseKey), m_decreaseKey(decreaseKey)
        {

        }

        KeyboardInputAxis::KeyboardInputAxis(const KeyboardInputAxis& axis)
            :InputAxis(axis), m_increaseKey(axis.m_increaseKey), m_decreaseKey(axis.m_decreaseKey)
        {

        }

        KeyboardInputAxis& KeyboardInputAxis::operator=(const KeyboardInputAxis& axis)
        {
            InputAxis::operator=(axis);

            m_increaseKey = axis.m_increaseKey;
            m_decreaseKey = axis.m_decreaseKey;

            return (*this);
        }

        KeyboardInputAxis::~KeyboardInputAxis()
        {

        }

        const bool KeyboardInputAxis::decrease()
        {
            return Keyboard::down(m_decreaseKey);
        }

        const bool KeyboardInputAxis::increase()
        {
            return Keyboard::down(m_increaseKey);
        }

    } // namespace Input

} // namespace SekaiEngine
