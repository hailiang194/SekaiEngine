#ifndef _OBJECT_GAME_OBJECT_H_
    #define _OBJECT_GAME_OBJECT_H_

#include "raylib.h"
#include <memory>
#include <limits>
#include <list>
#include <iostream>
#include <algorithm>
//#include "game_objects_container.h"

#define BOTTOM_Z_INDEX (int)0x80000000
#define TOP_Z_INDEX (int)0x7FFFFFFF

namespace SekaiEngine
{
    namespace Object
    {
        class GameObject
        {
        public:
            GameObject(const int& zIndex, const bool& alive = false);
            GameObject(const GameObject& object);
            GameObject& operator=(const GameObject& object);
            virtual ~GameObject();

            const bool& alive() const;
            const bool& alive();

            const GameObject* observer() const;
            const GameObject* observer();

            const int& zIndex() const;
            const int& zIndex();
            void setZIndex(const int& zIndex);

            //set new observer
            void observe(GameObject* observer);
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
            int m_zIndex;
            GameObject* m_observer;
        };

        inline const bool& GameObject::alive() const
        {
            return m_alive;
        }

        inline const bool& GameObject::alive()
        {
            return static_cast<const GameObject&>(*this).alive();
        }

        inline const GameObject* GameObject::observer() const
        {
            return m_observer;
        }

        inline const GameObject* GameObject::observer()
        {
            return static_cast<const GameObject&>(*this).observer();
        }

        inline void GameObject::observe(GameObject* observer)
        {
            m_observer = observer;
        }

        inline const int& GameObject::zIndex() const
        {
            return m_zIndex;
        }

        inline const int& GameObject::zIndex()
        {
            return static_cast<const GameObject&>(*this).zIndex();
        }

        class GameObjectsContainer: public GameObject
        {
        public:
            GameObjectsContainer(const int& zIndex = 0, const bool& alive = false);
            GameObjectsContainer(const GameObjectsContainer& container);
            GameObjectsContainer& operator=(const GameObjectsContainer& container);
            virtual ~GameObjectsContainer();

            void addGameObject(GameObject* child);
            void removeGameObject(GameObject* child, const bool& isDeleted = true);
            void clean();

            void updateZIndex(GameObject* updatedObject);

            void setup() override;

            virtual void setupThis() = 0;

            void update() override;

            virtual void updateThis() = 0;

            void draw() override;

            virtual void drawThis() = 0;

            void kill() override;

            virtual void killThis() = 0;
        protected:
            std::list<GameObject*> m_children;
            bool m_clean;
        };
    } // namespace Object
    
} // namespace SekaiEngine


#endif // _OBJECT_GAME_OBJECT_H_