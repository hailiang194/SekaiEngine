#ifndef _CORE_APPLICATION_
  #define _CORE_APPLICATION_

#include "raylib.h"
#include "game.h"
#include "../objects/scence.h"
#include <stdexcept>
#include <functional>
#include <iostream>

#define DEFAULT_EXCEPTION_CALLBACK [](const std::exception& e) { std::cout << e.what() << std::endl;}

namespace SekaiEngine
{
  namespace Core
  {
    class Application
    {
    public:
      Application(const std::string& title = "SekaiTemplate", const int& width = getMonitorWidth(), const int& height = getMonitorHeight());
      Application(const Application& app);
      Application& operator=(const Application& app);

      void addScence(const std::string& name, Object::Scence* scence);

      void start(const std::string& initScenceName, std::function<void(const std::exception&)> exceptionCallback = DEFAULT_EXCEPTION_CALLBACK);
    };
  } // namespace Core
  
} // namespace SekaiEngine


#endif // _CORE_APPLICATION_
