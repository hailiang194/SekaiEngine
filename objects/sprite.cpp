#include "./sprite.h"

namespace SekaiEngine
{
    namespace Object
    {
        Sprite::Sprite(const float& x, const float& y, const bool& alive)
            :GameObject(alive), m_x(x), m_y(y), m_observer(nullptr)
        {

        }

        Sprite::Sprite(const Sprite& sprite)
            :GameObject(sprite), m_x(sprite.m_x), m_y(sprite.m_y), m_observer(sprite.m_observer)
        {

        }

        Sprite& Sprite::operator=(const Sprite& sprite)
        {
            GameObject::operator=(sprite);

            m_x = sprite.m_x;
            m_y = sprite.m_y;
            m_observer = sprite.m_observer;

            return (*this);
        }

        Sprite::~Sprite()
        {

        }

        void Sprite::setup()
        {
            GameObject::setup();
        }
            
        void Sprite::update()
        {
            GameObject::update();
        }

        void Sprite::draw()
        {
            GameObject::draw();
        }

        void Sprite::kill()
        {
            GameObject::kill();
        }

    } // namespace Object
    
} // namespace SekaiEngine
