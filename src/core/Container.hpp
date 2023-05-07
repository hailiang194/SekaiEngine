#ifndef SEKAI_ENGINE_CORE_CONTAINER_HPP
#define SEKAI_ENGINE_CORE_CONTAINER_HPP

#include <list>
#include "./GameObject.hpp"

namespace SekaiEngine
{
    namespace Core
    {
        class Container: public GameObject
        {
        public:
            Container(const int &zIndex = 0, const bool &isAlive = false);
            Container(const Container& container);
            Container& operator=(const Container& container);
            virtual ~Container();

            virtual void interact();
            virtual void animate();
            virtual void event();
            virtual void render();
            virtual void preRender();

            void addObject(GameObject* child);
            void removeObject(GameObject* child, const bool& isDeleted = true);
        protected:
            // setup object when contructing
            void setup();

            // kill object when destroying
            void kill();

            void handleUpdateZIndex(GameObject* object);

            std::list<GameObject*> m_objects;
        };
    } // namespace Core
    
} // namespace SekaiEngine


#endif //!SEKAI_ENGINE_CORE_CONTAINER_HPP