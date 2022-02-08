#include "./sprite.h"

namespace SekaiEngine
{
    namespace Object
    {
        Sprite::Sprite(const Utility::Vector2D& position, const bool& alive)
            :GameObject(alive), m_position(position)
        {

        }

        Sprite::Sprite(const Sprite& sprite)
            :GameObject(sprite), m_position(sprite.m_position)
        {

        }

        Sprite& Sprite::operator=(const Sprite& sprite)
        {
            GameObject::operator=(sprite);
            m_position = sprite.m_position;

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
