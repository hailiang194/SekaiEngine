#include "input-manager.h"

namespace SekaiEngine
{
    namespace Input
    {
        InputManager::InputManager()
            :m_axies(), m_destroy(false)
        {

        }

        InputManager::InputManager(const InputManager& manager)
            :m_axies(manager.m_axies), m_destroy(manager.m_destroy)
        {

        }

        InputManager& InputManager::operator=(const InputManager& manager)
        {
            m_axies = manager.m_axies;
            m_destroy = manager.m_destroy;

            return (*this);
        }

        InputManager::~InputManager()
        {
            destroy();
        }

        void InputManager::addInputAxis(const std::string& name, InputAxis* axis)
        {
            if(m_axies.find(name) != m_axies.end())
            {
                throw std::invalid_argument("Existed axis");
            }

            m_axies.insert({name, axis});
        }

        void InputManager::destroy()
        {
            if(m_destroy)
            {
                return;
            }

            for(auto axisIter = m_axies.begin(); axisIter != m_axies.end(); ++axisIter)
            {
                delete (*axisIter).second;
            }
            m_axies.clear();

            m_destroy = true;
        }

        void InputManager::update()
        {
            for(auto axisIter = m_axies.begin(); axisIter != m_axies.end(); ++axisIter)
            {
                (*axisIter).second->update();
            }
        }
    } // namespace Input
    
} // namespace SekaiEngine
