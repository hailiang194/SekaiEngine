#ifndef _SEKAI_ENGINE_INPUT_GAMEPAD_H_
#define _SEKAI_ENGINE_INPUT_GAMEPAD_H_

#include <string>
#include "raylib.h"

namespace SekaiEngine
{
    namespace Input
    {
        class Gamepad
        {
        public:
            Gamepad(const int& id);
            Gamepad(const Gamepad& gamepad);
            Gamepad& operator=(const Gamepad& gamepad);
            ~Gamepad();

            const int& id() const;
            const int& id();

            const char * name() const;
            const char * name();

            const bool pressed(const int& button) const;
            const bool pressed(const int& button);

            const bool up(const int& button) const;
            const bool up(const int& button);

            const bool down(const int& button) const;
            const bool down(const int& button);

            const bool released(const int& button) const;
            const bool released(const int& button);

            const int totalAxis() const;
            const int totalAxis();

            const float axisMovement(const int& axis) const;
            const float axisMovement(const int& axis);

            static const int setGamepadMappings(const char* mappings);
            static const int pressedButton();
        private:
            int m_id;
        };    

        inline const int& Gamepad::id() const
        {
            return m_id;
        }

        inline const int& Gamepad::id()
        {
            return static_cast<const Gamepad&>(*this).id();
        }

        inline const char * Gamepad::name() const
        {
            return GetGamepadName(m_id);
        }

        inline const char * Gamepad::name()
        {
            return static_cast<const Gamepad&>(*this).name();
        }

        inline const bool Gamepad::pressed(const int& button) const
        {
            return IsGamepadButtonPressed(m_id, button);
        }

        inline const bool Gamepad::pressed(const int& button)
        {
            return static_cast<const Gamepad&>(*this).pressed(button);
        }

        inline const bool Gamepad::up(const int& button) const
        {
            return IsGamepadButtonUp(m_id, button);
        }

        inline const bool Gamepad::up(const int& button)
        {
            return static_cast<const Gamepad&>(*this).up(button);
        }

        const bool Gamepad::down(const int& button) const
        {
            return IsGamepadButtonDown(m_id, button);
        }

        inline const bool Gamepad::down(const int& button)
        {
            return static_cast<const Gamepad&>(*this).down(button);
        }

        inline const bool Gamepad::released(const int& button) const
        {
            return IsGamepadButtonReleased(m_id, button);
        }

        inline const bool Gamepad::released(const int& button)
        {
            return static_cast<const Gamepad&>(*this).released(button);
        }

        inline const int Gamepad::totalAxis() const
        {
            return GetGamepadAxisCount(m_id);
        }

        inline const int Gamepad::totalAxis()
        {
            return static_cast<const Gamepad&>(*this).totalAxis();
        }

        inline const float Gamepad::axisMovement(const int& axis) const
        {
            return GetGamepadAxisMovement(m_id, axis);
        }

        inline const float Gamepad::axisMovement(const int& axis)
        {
            return static_cast<const Gamepad&>(*this).axisMovement(axis);
        }

        inline const int Gamepad::setGamepadMappings(const char* mappings)
        {
            return SetGamepadMappings(mappings);
        }

        inline const int Gamepad::pressedButton()
        {
            return GetGamepadButtonPressed();
        }    
    } // namespace Input
    
} // namespace SekaiEngine


#endif //_SEKAI_ENGINE_INPUT_GAMEPAD_H_