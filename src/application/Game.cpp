#include <stdexcept>
#include "./Game.hpp"
#include "api/Image.hpp"

SekaiEngine::Application::Game* SekaiEngine::Application::Game::g_instance = nullptr;

void mainLoop(SekaiEngine::Application::Game* game)
{
    game->update();
}

SekaiEngine::Application::Game::Game(const std::string& title, const int& width, const int& height, const API::Ticker& ticker)
    :m_window(width, height, title), m_ticker(ticker), m_scences(), m_currentScence(nullptr)
{
    SekaiEngine::API::Image::init();
}

SekaiEngine::Application::Game::~Game()
{
    
}

SekaiEngine::API::Window& SekaiEngine::Application::Game::_window()
{
    return m_window;
}

void SekaiEngine::Application::Game::_insertScence(const std::string& name, Core::Scence* scence)
{
    if(m_scences.find(name) != m_scences.end())
    {
        throw std::invalid_argument("Scence is existed");
    }
    
    if(scence == nullptr)
    {
        throw std::invalid_argument("Scence is nullptr");
    }

    m_scences.insert({name, scence});
}
void SekaiEngine::Application::Game::_changeScence(const std::string& name, const bool& destroyOldScence)
{
    auto changedScence = m_scences.at(name);
    if(changedScence == nullptr)
    {
        throw std::invalid_argument("Nullptr Scence");
    }

    if(m_currentScence != nullptr && destroyOldScence)
    {
        m_currentScence->destroy();
    }

    m_currentScence = changedScence;
    changedScence->setup();
}

void SekaiEngine::Application::Game::_start()
{
    m_ticker.start();
#ifdef RAYLIB_API

#ifdef PLATFORM_WEB
    emscripten_set_main_loop_arg(mainLoop, (void*)this, 0, 1);
#else
    while(!m_window.shouldClose())
    {
        mainLoop(this);
    }
#endif

#else

#endif
}

void SekaiEngine::Application::Game::_update()
{
    if(m_currentScence == nullptr)
    {
        throw std::runtime_error("Scence is nullptr");
    }

    m_currentScence->update();
    m_currentScence->render();
}

void SekaiEngine::Application::Game::_exit()
{
    SekaiEngine::API::Image::unload();
    for(auto iter = m_scences.begin(); iter != m_scences.end(); ++iter)
    {
        delete (*iter).second;
    }
    m_scences.clear();
}