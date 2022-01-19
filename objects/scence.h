#ifndef _OBJECT_SCENCE_H_
    #define _OBJECT_SCENCE_H_

#include "raylib.h"
#include "game_object.h"
#include "sprite.h"
#include <vector>
#include <memory>
#include <stdexcept>
#include <iostream>
    
namespace SekaiEngine
{
    namespace Object
    {
        class Scence;

        typedef std::shared_ptr<Scence> Scence_ptr;

        class Scence: public GameObject
        {
        public:
            Scence(const Color& bgColor, const bool& alive = false);
            Scence(const Scence& scence);
            Scence& operator=(const Scence& scence);
            virtual ~Scence();

            virtual void setup();

            virtual void update();

            virtual void draw();

            virtual void kill();
            
            //add sprite and contruct it if it is not alive
            void addSprite(Sprite_ptr sprite);

            //destroy sprite if it is in the m_sprites and remove it
            void removeSprite(const Sprite_ptr& sprite);

            const Color& bgColor() const;
            Color& bgColor();

        protected:
            Color m_bgColor;
            std::vector<Sprite_ptr> m_sprites;
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