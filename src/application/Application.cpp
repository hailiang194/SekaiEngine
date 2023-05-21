#include "./Application.hpp"

SekaiEngine::Application::Application::Application(const std::string& title, const int& width, const int& height, const API::Ticker& ticker)
{
    Game::init(title, width, height, ticker);
}

SekaiEngine::Application::Application::~Application()
{
    Game::deleteInstance();
}

void SekaiEngine::Application::Application::addScrence(const std::string& name, Core::Scence* scence)
{
    Game::insertScence(name, scence);
}

void SekaiEngine::Application::Application::start(const std::string& initScenceName, std::function<void(const std::exception&)> exceptionCallback)
{
    Game::changeScence(initScenceName);
    try
    {
        Game::start();
        Game::exit();
    } 
    catch(std::exception& ex)
    {
        exceptionCallback(ex);
        Game::exit();
    }
}