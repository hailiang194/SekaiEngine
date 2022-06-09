#include "gamepad.h"

namespace SekaiEngine
{
    namespace Input
    {
        Gamepad::Gamepad(const int& id)
            :m_id(id)
        {

        }

        Gamepad::Gamepad(const Gamepad& gamepad)
            :m_id(gamepad.m_id)
        {

        }

        Gamepad& Gamepad::operator=(const Gamepad& gamepad)
        {
            m_id = gamepad.m_id;

            return (*this);
        }

        Gamepad::~Gamepad()
        {

        }

    } // namespace Input
    
} // namespace SekaiEngine
