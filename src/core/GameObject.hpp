#ifndef SEKAI_ENGINE_CORE_GAME_OBJECT_HPP
#define SEKAI_ENGINE_CORE_GAME_OBJECT_HPP

namespace SekaiEngine
{
    namespace Core
    {
        class GameObject
        {
        public:
            GameObject(const int &zIndex = 0, const bool &isAlive = false);
            GameObject(const GameObject &object);
            GameObject &operator=(const GameObject &object);
            virtual ~GameObject();

            const int &zIndex() const;
            const int &zIndex();
            void updateZIndex(const int &zIndex);

            const bool &alive() const;
            const bool &alive();

            const GameObject *observer() const;
            const GameObject *observer();

            void observe(GameObject *observer);

            // contruct object
            void construct();

            // destroy object
            void destroy();

            // Inside loop in order
            virtual void interact() = 0;
            virtual void animate() = 0;
            virtual void event() = 0;
            virtual void render() = 0;
            virtual void postRender() = 0;

        protected:
            // setup object when contructing
            virtual void setup() = 0;

            // kill object when destroying
            virtual void kill() = 0;

            virtual void handleUpdateZIndex(GameObject* object) = 0;

            bool m_isAlive;
            int m_zIndex;
            GameObject *m_observer;
        };

        inline const int &GameObject::zIndex() const
        {
            return m_zIndex;
        }

        inline const int &GameObject::zIndex()
        {
            return static_cast<const GameObject &>(*this).zIndex();
        }

        inline const bool &GameObject::alive() const
        {
            return m_isAlive;
        }

        inline const bool &GameObject::alive()
        {
            return static_cast<const GameObject &>(*this).alive();
        }

        inline const GameObject *GameObject::observer() const
        {
            return m_observer;
        }

        inline const GameObject *GameObject::observer()
        {
            return static_cast<const GameObject &>(*this).observer();
        }

        inline void GameObject::observe(GameObject *observer)
        {
            m_observer = observer;
        }
    } // namespace Core

} // namespace SekaiEngine

#endif //! SEKAI_ENGINE_CORE_GAME_OBJECT_HPP