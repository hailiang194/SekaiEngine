#include "game_object.h"

namespace SekaiEngine
{
    namespace Object
    {
        GameObject::GameObject(const bool& alive)
            :m_alive(alive), m_observer(nullptr)
        {

        }

        GameObject::GameObject(const GameObject& object)
            :m_alive(object.m_alive), m_observer(object.m_observer)
        {

        }

        GameObject& GameObject::operator=(const GameObject& object)
        {
            m_alive = object.m_alive;
            m_observer = object.m_observer;

            return (*this);
        }
        
        GameObject::~GameObject()
        {
            
        }

        void GameObject::contruct()
        {
            m_alive = true;
            setup();
        }

        void GameObject::setup()
        {

        }

        void GameObject::update()
        {

        }

        void GameObject::draw()
        {

        }

        void GameObject::kill()
        {

        }

        void GameObject::destroy()
        {
            kill();
            m_alive = false;
        }
    } // namespace Object
    
} // namespace SekaiEngine
