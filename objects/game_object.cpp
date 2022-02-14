#include "game_object.h"

namespace SekaiEngine
{
    namespace Object
    {
        GameObject::GameObject(const int& zIndex, const bool& alive)
            :m_alive(alive), m_zIndex(zIndex), m_observer(nullptr)
        {

        }

        GameObject::GameObject(const GameObject& object)
            :m_zIndex(object.m_zIndex), m_alive(object.m_alive), m_observer(object.m_observer)
        {

        }

        GameObject& GameObject::operator=(const GameObject& object)
        {
            m_zIndex = object.m_zIndex;
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

        void GameObject::setZIndex(const int& zIndex)
        {
            m_zIndex = zIndex;
            GameObjectsContainer* pContainer = dynamic_cast<GameObjectsContainer*>(m_observer);
            if(pContainer != nullptr)
            {
                pContainer->updateZIndex(this);
            }
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
