#include <stdexcept>
#include "./Container.hpp"

SekaiEngine::Core::Container::Container(const int &zIndex, const bool &isAlive)
    : SekaiEngine::Core::GameObject(zIndex, isAlive), m_objects()
{
}

SekaiEngine::Core::Container::Container(const SekaiEngine::Core::Container &container)
    : SekaiEngine::Core::GameObject(container), m_objects(container.m_objects)
{
}

SekaiEngine::Core::Container &SekaiEngine::Core::Container::operator=(const SekaiEngine::Core::Container &container)
{
    SekaiEngine::Core::GameObject::operator=(container);
    m_objects = container.m_objects;
    return (*this);
}

SekaiEngine::Core::Container::~Container()
{
}

void SekaiEngine::Core::Container::interact()
{
    for (auto iter = m_objects.begin(); iter != m_objects.end(); ++iter)
    {
        if ((*iter) != nullptr)
            (*iter)->interact();
    }
}

void SekaiEngine::Core::Container::animate()
{
    for (auto iter = m_objects.begin(); iter != m_objects.end(); ++iter)
    {
        if ((*iter) != nullptr)
            (*iter)->animate();
    }
}

void SekaiEngine::Core::Container::event()
{
    for (auto iter = m_objects.begin(); iter != m_objects.end(); ++iter)
    {
        if ((*iter) != nullptr)
            (*iter)->event();
    }
}

void SekaiEngine::Core::Container::render()
{
    for (auto iter = m_objects.begin(); iter != m_objects.end(); ++iter)
    {
        if ((*iter) != nullptr)
            (*iter)->render();
    }
}

void SekaiEngine::Core::Container::preRender()
{
    for (auto iter = m_objects.begin(); iter != m_objects.end(); ++iter)
    {
        if ((*iter) != nullptr)
            (*iter)->preRender();
    }
}

void SekaiEngine::Core::Container::addObject(GameObject *child)
{
    if(child == nullptr)
        throw std::invalid_argument("Can\'t add null-pointer child");
    
    child->observe(this);
    if(m_isAlive && !child->alive())
    {
        child->construct();
    }

    m_objects.push_back(child);
    handleUpdateZIndex(child);
}

void SekaiEngine::Core::Container::removeObject(GameObject *child, const bool &isDeleted)
{
    if(child == nullptr || m_objects.size() == 0)
        return;

    auto foundChildIter = std::find(m_objects.begin(), m_objects.end(), child);
    if(foundChildIter == m_objects.end())
        return;

    (*foundChildIter)->observe(nullptr);
    m_objects.erase(foundChildIter);
    if(child != nullptr && isDeleted)
        delete child;
} 

void SekaiEngine::Core::Container::setup()
{
    for (auto iter = m_objects.begin(); iter != m_objects.end(); ++iter)
    {
        if ((*iter) != nullptr && (*iter)->alive())
            (*iter)->construct();
    }
}

void SekaiEngine::Core::Container::kill()
{
    for (auto iter = m_objects.begin(); iter != m_objects.end(); ++iter)
    {
        if ((*iter) != nullptr && (*iter)->alive())
            (*iter)->destroy();
    }
}

void SekaiEngine::Core::Container::handleUpdateZIndex(GameObject* object)
{
    if(object == nullptr)
        return;

    auto iter = std::find(m_objects.begin(), m_objects.end(), object);
    if(iter == m_objects.end())
        return;

    m_objects.erase(iter);
    //if z index is highest in container
    if(m_objects.size() == 0 || m_objects.back()->zIndex() <= object->zIndex())
    {
        m_objects.push_back(object);
        return;
    }

    //if z index is lowest in container
    if(m_objects.front()->zIndex() > object->zIndex())
    {
        m_objects.push_front(object);
        return;
    }

    auto lastIterChild = std::prev(m_objects.end());
    for(auto iterChild = m_objects.begin(); iterChild != lastIterChild; ++iterChild)
    {
        auto nextIterChild = std::next(iterChild);
        if((*iterChild)->zIndex() <= object->zIndex() && object->zIndex() < (*nextIterChild)->zIndex())
        {
            m_objects.insert(nextIterChild, object);
            break;
        }
    }

}