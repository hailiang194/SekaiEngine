#include "game_object.h"

namespace SekaiEngine
{
    namespace Object
    {
        GameObjectsContainer::GameObjectsContainer(const int& zIndex, const bool& alive)
            :GameObject(zIndex, alive), m_children(), m_clean(true)
        {

        }

        GameObjectsContainer::GameObjectsContainer(const GameObjectsContainer& container)
            :GameObject(container), m_children(container.m_children), m_clean(container.m_clean)
        {

        }

        GameObjectsContainer& GameObjectsContainer::operator=(const GameObjectsContainer& container)
        {
            GameObject::operator=(container);
            m_children = container.m_children;
            m_clean = container.m_clean;

            return (*this);
        }

        GameObjectsContainer::~GameObjectsContainer()
        {
            clean();
        }

        void GameObjectsContainer::addGameObject(GameObject* child)
        {
            if(child == nullptr)
            {
                throw std::invalid_argument("Can\'t add null-pointer child");
            }

            child->observe(this);
            if(m_alive)
            {
                
            }

            if(m_children.size() == 0 || m_children.back()->zIndex() <= child->zIndex())
            {
                m_children.push_back(child);
                m_clean = false;
                return;
            }

            //m_children.push_back(child);

            if(m_children.front()->zIndex() > child->zIndex())
            {
                m_children.push_front(child);
                m_clean = false;
                return;
            }

            auto lastIterChild = std::prev(m_children.end());
            for(auto iterChild = m_children.begin(); iterChild != lastIterChild; ++iterChild)
            {
                auto nextIterChild = std::next(iterChild);
                if((*iterChild)->zIndex() <= child->zIndex() && child->zIndex() < (*nextIterChild)->zIndex())
                {
                    m_children.insert(nextIterChild, child);
                    break;
                }
            }

            m_clean = false;
        }

        void GameObjectsContainer::removeGameObject(GameObject* child, const bool& isDeleted)
        {
            if(child == nullptr || m_children.size() == 0)
            {
                return;
            }

            auto foundChildIter = std::find(m_children.begin(), m_children.end(), child);
            if(foundChildIter == m_children.end())
            {
                return;
            }

            m_children.erase(foundChildIter);
            if((*foundChildIter) != nullptr && isDeleted)
            {
                delete (*foundChildIter);
            }
        }

        void GameObjectsContainer::clean()
        {
            if(m_clean)
            {
                return;
            }

            for(auto child = m_children.begin(); child != m_children.end(); ++child)
            {
                if(*child != nullptr)
                {
                    delete *child;
                }
            }

            m_children.clear();
        }

        void GameObjectsContainer::updateZIndex(GameObject* updatedObject)
        {
            if(updatedObject == nullptr)
            {
                return;
            }

            auto updatedIter = std::find(m_children.begin(), m_children.end(), updatedObject);
            if(updatedIter == m_children.end())
            {
                return;
            }

            m_children.erase(updatedIter);
            if(m_children.size() == 0 || m_children.back()->zIndex() <= updatedObject->zIndex())
            {
                m_children.push_back(updatedObject);
                return;
            }

            if(m_children.front()->zIndex() > updatedObject->zIndex())
            {
                m_children.push_front(updatedObject);
                return;
            }

            auto lastIterChild = std::prev(m_children.end());
            for(auto iterChild = m_children.begin(); iterChild != lastIterChild; ++iterChild)
            {
                auto nextIterChild = std::next(iterChild);
                if((*iterChild)->zIndex() <= updatedObject->zIndex() && updatedObject->zIndex() < (*nextIterChild)->zIndex())
                {
                    m_children.insert(nextIterChild, updatedObject);
                    break;
                }
            }

        }

        void GameObjectsContainer::setup()
        {
            GameObject::setup();
            for(auto child = m_children.begin(); child != m_children.end(); ++child)
            {
                (*child)->setup();
            }

        }

        void GameObjectsContainer::update()
        {
            GameObject::update();
            for(auto child = m_children.begin(); child != m_children.end(); ++child)
            {
                if((*child)->alive())
                    (*child)->update();
            }
        }

        void GameObjectsContainer::draw()
        {
            GameObject::draw();
            for(auto child = m_children.begin(); child != m_children.end(); ++child)
            {
                if((*child)->alive())
                    (*child)->draw();
            }
        }

        void GameObjectsContainer::kill()
        {
            GameObject::kill();
            for(auto child = m_children.begin(); child != m_children.end(); ++child)
            {
                (*child)->kill();
            }
        }
    } // namespace Object
    
} // namespace SekaiEngine
