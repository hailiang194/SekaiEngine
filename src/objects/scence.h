#ifndef _OBJECT_SCENCE_H_
    #define _OBJECT_SCENCE_H_

#include "raylib.h"
#include "game_object.h"
#include <vector>
#include <memory>
#include <stdexcept>
#include <algorithm>
    
namespace SekaiEngine
{
    namespace Object
    {
        class Scence: public GameObjectsContainer
        {
        public:
            Scence(const Color& bgColor, const bool& alive = false);
            Scence(const Scence& scence);
            Scence& operator=(const Scence& scence);
            virtual ~Scence();

            virtual void setupThis();

            virtual void updateThis();

            virtual void drawThis();

            virtual void killThis();

            const Color& bgColor() const;
            Color& bgColor();

        protected:
            Color m_bgColor;
        };

        inline const Color& Scence::bgColor() const
        {
            return m_bgColor;
        }

        inline Color& Scence::bgColor()
        {
            return const_cast<Color&>(static_cast<const Scence&>(*this).bgColor());
        }
    } // namespace Object
    
} // namespace SekaiEngine
    

#endif // _OBJECT_SCENCE_H_