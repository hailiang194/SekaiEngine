#include "./application.h"

namespace SekaiEngine
{
  namespace Core
  {
      Application::Application(const std::string& title, const int& width, const int& height)
      {
        Game::setTitle(title);
        Game::setSize(width, height);
        Game::init();
      }

      void Application::addScence(const std::string& name, Object::Scence* scence)
      {
        Game::scences().addScence(name, scence);
      }

      Application::Application(const Application& app)
      {

      }

      Application& Application::operator=(const Application& app)
      {
        return (*this);
      }


      void Application::start(const std::string& initScenceName, std::function<void(const std::exception&)> exceptionCallback)
      {
        try
        {
          Game::changeScence(initScenceName);
          Game::start();
          Game::exit();
        }catch(const std::exception& e)
        {
          exceptionCallback(e);
          Game::exit();
        }

      }
  } // namespace Core
  
} // namespace SekaiEngine
