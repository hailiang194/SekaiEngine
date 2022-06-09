#ifndef _CORE_GAME_
    #define _CORE_GAME_

#include "raylib.h"
#include "../objects/scence.h"
#include "scence_manager.h"
#include "asset-manager.h"
#include "../input/input-manager.h"
#include <stdexcept>

#if defined(PLATFORM_WEB)
    #include <emscripten/emscripten.h>
#endif

namespace SekaiEngine
{
    namespace Core
    {

        void main_loop();

        int getMonitorWidth();
        int getMonitorHeight();

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

            static void changeScence(const std::string& scenceName, const bool& destroyOldScence = true);

            static void setTitle(const char* title);
            static void setTitle(const std::string& title);

            static const std::string& title();

            static void setSize(const int& width, const int& height);

            static const int width();
            static const int height();

            static ScenceManager& scences();
            static const std::string& currentScenceName();

            static TexturesManager& textures();

            static Input::InputManager& input();

            static void init();
            static void start();
            static void update();
            static void exit();
        private:
            Object::Scence* m_scence;
            GameState m_state;
            std::string m_title;
            int m_width;
            int m_height;
            ScenceManager m_scences;
            std::string m_currentScenceName;
            TexturesManager m_textures;
            Input::InputManager m_input;


            Game();
            Game(const Game& game) = delete;
            Game& operator=(const Game& game) = delete;

            void _changeScence(const std::string& scenceName, const bool& destroyOldScence = true);

            void _setTitle(const std::string& title);
            const std::string& _title();
            void _setSize(const int& width, const int& height);
            const int _width();
            const int _height();
            
            ScenceManager& _scences();
            const std::string& _currentScenceName();

            TexturesManager& _textures();

            Input::InputManager& _input();

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

        inline void Game::changeScence(const std::string& scenceName, const bool& destroyOldScence)
        {
            Game::instance()._changeScence(scenceName, destroyOldScence);
        }

        inline Input::InputManager& Game::input()
        {
            return Game::instance()._input();
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

        inline ScenceManager& Game::scences()
        {
            return Game::instance()._scences();
        }

        inline const std::string& Game::currentScenceName()
        {
            return Game::instance()._currentScenceName();
        }

        inline TexturesManager& Game::textures()
        {
            return Game::instance()._textures();
        }
    } // namespace Core
    
} // namespace SekaiEngine


#endif // _CORE_GAME_
