#ifndef _CORE_APPLICATION_
  #define _CORE_APPLICATION_

#include "raylib.h"
#include "game.h"
#include "../objects/scence.h"

namespace SekaiEngine
{
  namespace Core
  {
    class Application
    {
    public:
      Application(const std::string& title = "SekaiTemplate", const int& width = FULL_SIZE, const int& height = FULL_SIZE);
      Application(const Application& app);
      Application& operator=(const Application& app);

      void setTitle(const std::string& title);
      void start(const SekaiEngine::Object::Scence_ptr& initScence);
    };
  } // namespace Core
  
} // namespace SekaiEngine


#endif // _CORE_APPLICATION_
