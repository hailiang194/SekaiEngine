#ifndef _CORE_GAME_
    #define _CORE_GAME_

#include "raylib.h"
#include "../objects/scence.h"
#include <stdexcept>

#define FULL_SIZE 0

#if defined(PLATFORM_WEB)
    #include <emscripten/emscripten.h>
#endif

namespace SekaiEngine
{
    namespace Core
    {

        void main_loop();

        enum class GameState
        {
            CREATE, //Game has been contructed
            INITIALIZE, // init() has been called
            START, // start() has been called
            EXIT // exit() has been called
        };

        class Game
        {
        public:
            static Game& instance();

            static void changeScence(const SekaiEngine::Object::Scence_ptr& changedScence, const bool& destroyOldScence = true);

            static void setTitle(const char* title);
            static void setTitle(const std::string& title);

            static const std::string& title();

            static void setSize(const int& width, const int& height);

            static const int width();
            static const int height();

            static void init();
            static void start();
            static void update();
            static void exit();
        private:
            SekaiEngine::Object::Scence_ptr m_scence;
            GameState m_state;
            std::string m_title;
            int m_width;
            int m_height;


            Game();
            Game(const Game& game) = delete;
            Game& operator=(const Game& game) = delete;

            void _changeScence(const SekaiEngine::Object::Scence_ptr& changedScence, const bool& destroyOldScence = true);

            void _setTitle(const std::string& title);
            const std::string& _title();
            void _setSize(const int& width, const int& height);
            const int _width();
            const int _height();

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

        inline const std::string& Game::title()
        {
            return Game::instance()._title();
        }

        inline void Game::setTitle(const char* title)
        {
            if(title == nullptr)
                throw std::invalid_argument("Title can\'t be nullptr");
            
            Game::instance()._setTitle(title);
        }

        inline void Game::setTitle(const std::string& title)
        {
            Game::instance()._setTitle(title);
        }

        inline void Game::setSize(const int& width, const int& height)
        {
            Game::instance()._setSize(width, height);
        }

        inline const int Game::width()
        {
            return Game::instance()._width();
        }

        inline const int Game::height()
        {
            return Game::instance()._height();
        }
    } // namespace Core
    
} // namespace SekaiEngine


#endif // _CORE_GAME_
