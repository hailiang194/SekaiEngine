#ifndef _OBJECT_SPRITE_H_
    #define _OBJECT_SPRITE_H_

#include "game_object.h"
#include <memory>

namespace SekaiEngine
{
    namespace Object
    {
        class Sprite: public GameObject
        {
        public:
            Sprite(const float& x, const float& y, const bool& alive = false);
            Sprite(const Sprite& sprite);
            Sprite& operator=(const Sprite& sprite);
            virtual ~Sprite();

            const float& x() const;
            float& x();

            const float& y() const;
            float& y();

            const GameObject_ptr& observer() const;
            const GameObject_ptr& observer();

            //set new observer
            void observe(const GameObject_ptr& observer);

            virtual void setup();
            
            virtual void update();

            virtual void draw();

            virtual void kill();

        protected:
            float m_x;
            float m_y;
            GameObject_ptr m_observer;
        };

        typedef std::shared_ptr<Sprite> Sprite_ptr;

        inline const float& Sprite::x() const
        {
            return m_x;
        }

        inline float& Sprite::x()
        {
            return const_cast<float&>(static_cast<const Sprite&>(*this).x());
        }

        inline const float& Sprite::y() const
        {
            return m_y;
        }

        inline float& Sprite::y()
        {
            return const_cast<float&>(static_cast<const Sprite&>(*this).y());
        }

        inline const GameObject_ptr& Sprite::observer() const
        {
            return m_observer;
        }

        inline const GameObject_ptr& Sprite::observer()
        {
            return static_cast<const Sprite&>(*this).observer();
        }

        inline void Sprite::observe(const GameObject_ptr& observer)
        {
            m_observer = observer;
        }
    } // namespace Object
    
} // namespace SekaiEngine


#endif // _OJBECT_SPRITE_H_