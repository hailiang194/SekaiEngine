#include "./application.h"

namespace SekaiEngine
{
  namespace Core
  {
      Application::Application()
      {

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
