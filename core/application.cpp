#include "./application.h"

namespace SekaiEngine
{
  namespace Core
  {
      Application::Application(const std::string& title, const int& width, const int& height)
      {
        Game::setTitle(title);
        Game::setSize(width, height);
      }

      Application::Application(const Application& app)
      {

      }

      Application& Application::operator=(const Application& app)
      {
        return (*this);
      }


      void Application::start(const SekaiEngine::Object::Scence_ptr& initScence)
      {
        Game::changeScence(initScence);
        Game::init();
        Game::start();
        Game::exit();
      }
  } // namespace Core
  
} // namespace SekaiEngine
