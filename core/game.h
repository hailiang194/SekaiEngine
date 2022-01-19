#ifndef _CORE_GAME_
    #define _CORE_GAME_

#include "raylib.h"
#include "../objects/scence.h"
#include <stdexcept>

#if defined(PLATFORM_WEB)
    #include <emscripten/emscripten.h>
#endif

namespace SekaiEngine
{
    namespace Core
    {

        void main_loop();

        class Game
        {
        public:
            static Game& instance();

            static void changeScence(const SekaiEngine::Object::Scence_ptr& changedScence, const bool& destroyOldScence = true);

            static void init();
            static void start();
            static void update();
            static void exit();
        private:
            SekaiEngine::Object::Scence_ptr m_scence;

            Game();
            Game(const Game& game) = delete;
            Game& operator=(const Game& game) = delete;

            void _changeScence(const SekaiEngine::Object::Scence_ptr& changedScence, const bool& destroyOldScence = true);

            void _init();
            void _start();
            void _update();
            void _exit();
        };

        inline Game& Game::instance()
        {
            static Game game;
            return game;
        }

        inline void Game::changeScence(const SekaiEngine::Object::Scence_ptr& changedScence, const bool& destroyOldScence)
        {
            Game::instance()._changeScence(changedScence, destroyOldScence);
        }

        inline void Game::init()
        {
            Game::instance()._init();
        }
        inline void Game::start()
        {
            Game::instance()._start();
        }

        inline void Game::update()
        {
            Game::instance()._update();
        }

        inline void Game::exit()
        {
            Game::instance()._exit();
        }
    } // namespace Core
    
} // namespace SekaiEngine


#endif // _CORE_GAME_
