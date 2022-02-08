#ifndef _OBJECT_GAME_OBJECT_H_
    #define _OBJECT_GAME_OBJECT_H_

#include "raylib.h"
#include <memory>

namespace SekaiEngine
{
    namespace Object
    {
        class GameObject;

        typedef std::shared_ptr<GameObject> GameObject_ptr;

        class GameObject
        {
        public:
            GameObject(const bool& alive = false);
            GameObject(const GameObject& object);
            GameObject& operator=(const GameObject& object);
            virtual ~GameObject();

            const bool& alive() const;
            const bool& alive();

            const GameObject_ptr& observer() const;
            const GameObject_ptr& observer();

            //set new observer
            void observe(const GameObject_ptr& observer);
            //make object alive and run setup
            void contruct();

            //run only once when object has just been alive
            virtual void setup();

            //update object in each frame
            virtual void update();

            //draw object
            virtual void draw();

            //pre-destroy function
            virtual void kill();

            //destroy game object
            void destroy();

        protected:
            bool m_alive;
            GameObject_ptr m_observer;
        };

        

        inline const bool& GameObject::alive() const
        {
            return m_alive;
        }

        inline const bool& GameObject::alive()
        {
            return static_cast<const GameObject&>(*this).alive();
        }

        inline const GameObject_ptr& GameObject::observer() const
        {
            return m_observer;
        }

        inline const GameObject_ptr& GameObject::observer()
        {
            return static_cast<const GameObject&>(*this).observer();
        }

        inline void GameObject::observe(const GameObject_ptr& observer)
        {
            m_observer = observer;
        }
    } // namespace Object
    
} // namespace SekaiEngine


#endif // _OBJECT_GAME_OBJECT_H_