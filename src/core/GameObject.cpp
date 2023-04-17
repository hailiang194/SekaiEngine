#include "./GameObject.hpp"

SekaiEngine::Core::GameObject::GameObject(const int& zIndex, const bool& isAlive)
    :m_zIndex(zIndex), m_isAlive(isAlive), m_observer(nullptr)
{

}

SekaiEngine::Core::GameObject::GameObject(const SekaiEngine::Core::GameObject& object)
    :m_zIndex(object.m_zIndex), m_isAlive(object.m_isAlive), m_observer(object.m_observer)
{

}

SekaiEngine::Core::GameObject& SekaiEngine::Core::GameObject::operator=(const SekaiEngine::Core::GameObject& object)
{
    m_zIndex = object.m_zIndex;
    m_isAlive = object.m_isAlive;
    m_observer = object.m_observer;

    return (*this);
}

SekaiEngine::Core::GameObject::~GameObject()
{

}

void SekaiEngine::Core::GameObject::updateZIndex(const int& zIndex)
{
    m_zIndex = zIndex;
    if(m_observer != nullptr)
    {
        m_observer->handleUpdateZIndex(this);
    }
}

void SekaiEngine::Core::GameObject::construct()
{
    m_isAlive = true;
    setup();
}

void SekaiEngine::Core::GameObject::destroy()
{
    kill();
    m_isAlive = false;
}