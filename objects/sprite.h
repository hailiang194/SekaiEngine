#ifndef _OBJECT_SPRITE_H_
    #define _OBJECT_SPRITE_H_

#include "game_object.h"
#include "../utility/vector2d.h"
#include <memory>

namespace SekaiEngine
{
    namespace Object
    {
        class Sprite: public GameObject
        {
        public:
            Sprite(const Utility::Vector2D& position = Utility::Vector2D(), const bool& alive = false);
            Sprite(const Sprite& sprite);
            Sprite& operator=(const Sprite& sprite);
            virtual ~Sprite();

            const Utility::Vector2D& position() const;
            Utility::Vector2D& position();

            virtual void setup();
            
            virtual void update();

            virtual void draw();

            virtual void kill();

        protected:
            Utility::Vector2D m_position;
        };

        inline const Utility::Vector2D& Sprite::position() const
        {
            return m_position;
        }

        inline Utility::Vector2D& Sprite::position()
        {
            return const_cast<Utility::Vector2D&>(static_cast<const Sprite&>(*this).position());
        }
    } // namespace Object
    
} // namespace SekaiEngine


#endif // _OJBECT_SPRITE_H_