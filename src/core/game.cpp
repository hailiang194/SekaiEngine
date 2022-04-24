#include "game.h"

namespace SekaiEngine
{
    namespace Core
    {

        void main_loop()
        {
            Game::update();
        }

        int getMonitorWidth()
        {
#if defined(PLATFORM_WEB)
            return EM_ASM_INT({
                return window.innerWidth;
                });
#else
            return 0;
#endif
        }

        int getMonitorHeight()
        {
#if defined(PLATFORM_WEB)
            return EM_ASM_INT({
                return window.innerHeight;
                });
#else
	        return 0;
#endif
        }

        Game::Game()
            : m_scence(nullptr), m_state(GameState::CREATE), 
            m_title("SekaiEngine"), m_width(getMonitorWidth()),
            m_height(getMonitorHeight()), m_scences(), m_currentScenceName("")
        {
        }

        void Game::_setTitle(const std::string &title)
        {
            m_title = title;

            if (IsWindowReady())
            {
                SetWindowTitle(m_title.c_str());
            }
        }

        const std::string& Game::_title()
        {
            return m_title;
        }

        void Game::_setSize(const int &width, const int &height)
        {
            if (width < 0)
                throw std::invalid_argument("Width must be greater than 0");
            if (height < 0)
                throw std::invalid_argument("Height must be greater than 0");

            m_width = width;
            m_height = height;

            if (IsWindowReady())
            {
                SetWindowSize(m_width, m_height);
            }
        }

        const int Game::_width()
        {
            return GetScreenWidth();
        }

        const int Game::_height()
        {
            return GetScreenHeight();
        }

        ScenceManager& Game::_scences()
        {
            return m_scences;
        }

        const std::string& Game::_currentScenceName()
        {
            return m_currentScenceName;
        }

        void Game::_changeScence(const std::string& scenceName, const bool& destroyOldScence)
        {
            Object::Scence* changedScence = m_scences.getScence(scenceName);
            if(changedScence == nullptr)
            {
                throw std::invalid_argument("Can\'t run with to the null-pointer scence");
            }

            if (m_scence != nullptr && destroyOldScence)
            {
                m_scence->destroy();
            }

            m_currentScenceName = scenceName;
            m_scence = changedScence;
            m_scence->contruct();
        }

        void Game::_init()
        {
            if (m_state != GameState::CREATE)
                throw std::runtime_error("Game has been initialized");

            m_state = GameState::INITIALIZE;
            InitWindow(m_width, m_height, m_title.c_str());
        }

        void Game::_start()
        {

            switch (m_state)
            {
            case GameState::INITIALIZE:
                m_state = GameState::START;
                break;
            case GameState::START:
                break;
            default:
                throw std::runtime_error("Unable to start game");
                break;
            }

#if defined(PLATFORM_WEB)
            emscripten_set_main_loop(main_loop, 0, 1);
#else
            SetTargetFPS(60);
            //--------------------------------------------------------------------------------------

            // Main game loop
            while (!WindowShouldClose())
            {
                main_loop();
            }
#endif
        }

        void Game::_update()
        {
            BeginDrawing();

            if (m_scence == nullptr)
            {
                throw std::runtime_error("Can\'t update null-pointer scence");
            }

            m_scence->update();
            m_scence->draw();

            EndDrawing();
        }

        void Game::_exit()
        {
            if (m_state == GameState::EXIT)
                return;

            m_scences.clean();
            m_state = GameState::EXIT;
            CloseWindow();
        }
    } // namespace Core

} // namespace SekaiEngine
