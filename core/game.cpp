#include "game.h"

namespace SekaiEngine
{
    namespace Core
    {

        void main_loop()
        {
            Game::update();
        }

        Game::Game()
            :m_scence(nullptr)
        {

        }
        void Game::_changeScence(const SekaiEngine::Object::Scence_ptr& changedScence, const bool& destroyOldScence)
        {
            if(changedScence == nullptr)
            {
                throw std::invalid_argument("Can\'t change to the null-pointer scence");
            }

            if(m_scence != nullptr && destroyOldScence)
            {
                m_scence->destroy();
            }

            m_scence = changedScence;
            m_scence->contruct();
        }

        void Game::_init()
        {
            InitWindow(800, 400, "SekaiEngine");
        }

        void Game::_start()
        {

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

            if(m_scence == nullptr)
            {
                throw std::runtime_error("Can\'t update null-pointer scence");
            }

            m_scence->update();
            m_scence->draw();

            EndDrawing();           
        }

        void Game::_exit()
        {
            CloseWindow();
        }
    } // namespace Core
    
} // namespace SekaiEngine
