#include "scence.h"

namespace SekaiEngine
{
    namespace Object
    {
        Scence::Scence(const Color& bgColor, const bool& alive)
            :GameObjectsContainer(BOTTOM_Z_INDEX, true), m_bgColor(bgColor), m_sprites()
        {

        }

        Scence::Scence(const Scence& scence)
            :GameObjectsContainer(scence), m_bgColor(scence.m_bgColor), m_sprites(scence.m_sprites)
        {
            
        }
        Scence& Scence::operator=(const Scence& scence)
        {
            GameObjectsContainer::operator=(scence);
            m_bgColor = scence.m_bgColor;
            m_sprites = scence.m_sprites;
            return (*this);
        }

        Scence::~Scence()
        {

        }

        void Scence::setup()
        {
            GameObjectsContainer::setup();
        }

        void Scence::update()
        {
            GameObjectsContainer::update();
        }

        void Scence::draw()
        {
            ClearBackground(m_bgColor);
            GameObjectsContainer::draw();
        }

        void Scence::kill()
        {
            GameObjectsContainer::kill();

        }
    } // namespace Object
    
} // namespace SekaiEngine
