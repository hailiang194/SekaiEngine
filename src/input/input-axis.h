#ifndef _SEKAI_ENGINE_INPUT_AXIS_H_
#define _SEKAI_ENGINE_INPUT_AXIS_H_

#define DEFAULT_ADJUST 0.1f
#define RAW_ADJUST 1.0f

#include "../utility/math.h"
#include "keyboard.h"
#include <string>

namespace SekaiEngine
{
    namespace Input
    {
        class InputAxis
        {
        public:
            InputAxis(const float& adjust = DEFAULT_ADJUST, const float& value = 0.0f);
            InputAxis(const InputAxis& axis);
            InputAxis& operator=(const InputAxis& axis);
            virtual ~InputAxis();

            virtual const bool decrease() = 0;
            virtual const bool increase() = 0;

            void update();

            const float& adjust() const;
            const float& adjust();

            const float& value() const;
            const float& value();

        protected:
            float m_adjust;
            float m_value;
        };


        class KeyboardInputAxis : public InputAxis
        {
        public:
            KeyboardInputAxis(const int& increaseKey, const int& decreaseKey, const float& adjust = DEFAULT_ADJUST, const float& value = 0.0f);
            KeyboardInputAxis(const KeyboardInputAxis& axis);
            KeyboardInputAxis& operator=(const KeyboardInputAxis& axis);
            ~KeyboardInputAxis();

            const int& increaseKey() const;
            const int& increaseKey();

            const int& decreaseKey() const;
            const int& decreaseKey();

            const bool decrease() override;
            const bool increase() override;

        private:
            int m_increaseKey;
            int m_decreaseKey;
        };

        inline const float& InputAxis::adjust() const
        {
            return m_adjust;
        }

        inline const float& InputAxis::adjust()
        {
            return static_cast<const InputAxis&>(*this).adjust();
        }

        inline const float& InputAxis::value() const
        {
            return m_value;
        }

        inline const float& InputAxis::value()
        {
            return static_cast<const InputAxis&>(*this).value();
        }

        inline const int& KeyboardInputAxis::increaseKey() const
        {
            return m_increaseKey;
        }

        inline const int& KeyboardInputAxis::increaseKey()
        {
            return static_cast<const KeyboardInputAxis&>(*this).increaseKey();
        }

        inline const int& KeyboardInputAxis::decreaseKey() const
        {
            return m_decreaseKey;
        }

        inline const int& KeyboardInputAxis::decreaseKey()
        {
            return static_cast<const KeyboardInputAxis&>(*this).decreaseKey();
        }
        
    } // namespace Input
    
} // namespace SekaiEngine


#endif //_SEKAI_ENGINE_INPUT_AXIS_H_