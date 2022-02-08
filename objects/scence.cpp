#include "scence.h"

namespace SekaiEngine
{
    namespace Object
    {
        Scence::Scence(const Color& bgColor, const bool& alive)
            :GameObject(alive), m_bgColor(bgColor), m_sprites()
        {

        }

        Scence::Scence(const Scence& scence)
            :GameObject(scence), m_bgColor(scence.m_bgColor), m_sprites(scence.m_sprites)
        {
            
        }
        Scence& Scence::operator=(const Scence& scence)
        {
            GameObject::operator=(scence);
            m_bgColor = scence.m_bgColor;
            m_sprites = scence.m_sprites;
            return (*this);
        }

        Scence::~Scence()
        {

        }

        void Scence::setup()
        {
            GameObject::setup();
            for (auto &&sprite : m_sprites)
            {
                sprite->setup();
            }            
        }

        void Scence::update()
        {
            GameObject::update();
            for (auto &&sprite : m_sprites)
            {
                if(sprite->alive())
                    sprite->update();
            }
            
        }

        void Scence::draw()
        {
            GameObject::draw();
            ClearBackground(m_bgColor);
            for (auto &&sprite : m_sprites)
            {
                if(sprite->alive())
                    sprite->draw();
            }
        }

        void Scence::kill()
        {
            GameObject::kill();
            for (auto &&sprite : m_sprites)
            {
                sprite->kill();
            }
        }

        void Scence::addGameObject(GameObject_ptr sprite)
        {
            if(sprite == nullptr)
            {
                throw std::invalid_argument("Can\'t add null-pointer sprite");
            }
            if(!sprite->alive())
                sprite->contruct();

            sprite->observe(Scence_ptr(this));
            m_sprites.push_back(sprite);
        }

        void Scence::removeGameObject(const GameObject_ptr& sprite)
        {
            if(sprite == nullptr)
            {
                return;
            }

            auto rmSprite = std::find(m_sprites.begin(), m_sprites.end(), sprite);

            if(rmSprite != m_sprites.end())
            {
                (*rmSprite)->destroy();
                m_sprites.erase(rmSprite);
            }
        }
    } // namespace Object
    
} // namespace SekaiEngine
