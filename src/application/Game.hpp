#ifndef SEKAI_ENGINE_APPLICATION_GAME_HPP
#define SEKAI_ENGINE_APPLICATION_GAME_HPP

#include <string>
#include <unordered_map>
#include "core/Scence.hpp"
#include "api/Ticker.hpp"
#include "api/Window.hpp"

namespace SekaiEngine
{
    namespace Application
    {
        class Game
        {
        public:
            static Game* instance();
            static void init(const std::string& title, const int& width, const int& height, const API::Ticker& ticker);
            static void deleteInstance();

            static API::Window& window();

            static void insertScence(const std::string& name, Core::Scence* scence);
            static void changeScence(const std::string& name, const bool& destroyOldScence = true);
            
            static void start();
            static void update();
            static void exit();
        private:
            Game(const std::string& title, const int& width, const int& height, const API::Ticker& ticker);
            ~Game();

            static Game *g_instance;
            API::Window m_window;
            API::Ticker m_ticker;
            std::unordered_map<std::string, Core::Scence*> m_scences;
            Core::Scence* m_currentScence;

            API::Window& _window();

            void _insertScence(const std::string& name, Core::Scence* scence);
            void _changeScence(const std::string& name, const bool& destroyOldScence);
            
            void _start();
            void _update();
            void _exit();
        };

        inline Game* Game::instance()
        {
            return g_instance;
        }

        inline void Game::init(const std::string& title, const int& width, const int& height, const API::Ticker& ticker)
        {
            if(g_instance == nullptr)
            {
                g_instance = new Game(title, width, height, ticker);
            }
        }

        inline void Game::deleteInstance()
        {
            if(g_instance != nullptr)
            {
                delete g_instance;
                g_instance = nullptr;
            }
        }

        inline API::Window& Game::window()
        {
            return g_instance->_window();
        }

        inline void Game::insertScence(const std::string& name, Core::Scence* scence)
        {
            g_instance->_insertScence(name, scence);
        }

        inline void Game::changeScence(const std::string& name, const bool& destroyOldScence)
        {
            g_instance->_changeScence(name, destroyOldScence);
        }
        
        inline void Game::start()
        {
            g_instance->_start();
        }

        inline void Game::update()
        {
            g_instance->_update();
        }

        inline void Game::exit()
        {
            g_instance->_exit();
        }
    } // namespace Application
    
} // namespace SekaiEngine


#endif //!SEKAI_ENGINE_APPLICATION_GAME_HPP