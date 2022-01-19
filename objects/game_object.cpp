#include "game_object.h"

namespace SekaiEngine
{
    namespace Object
    {
        GameObject::GameObject(const bool& alive)
            :m_alive(alive)
        {

        }

        GameObject::GameObject(const GameObject& object)
            :m_alive(object.m_alive)
        {

        }

        GameObject& GameObject::operator=(const GameObject& object)
        {
            m_alive = object.m_alive;
            
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
