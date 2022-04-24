#include "scence.h"

namespace SekaiEngine
{
    namespace Object
    {
        Scence::Scence(const Color& bgColor, const bool& alive)
            :GameObjectsContainer(BOTTOM_Z_INDEX, true), m_bgColor(bgColor)
        {

        }

        Scence::Scence(const Scence& scence)
            :GameObjectsContainer(scence), m_bgColor(scence.m_bgColor)
        {
            
        }
        Scence& Scence::operator=(const Scence& scence)
        {
            GameObjectsContainer::operator=(scence);
            m_bgColor = scence.m_bgColor;
            return (*this);
        }

        Scence::~Scence()
        {

        }

        void Scence::setupThis()
        {
        }

        void Scence::updateThis()
        {
        }

        void Scence::drawThis()
        {
            ClearBackground(m_bgColor);
        }

        void Scence::killThis()
        {
        }
    } // namespace Object
    
} // namespace SekaiEngine
