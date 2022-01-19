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
      Application();
      Application(const Application& app);
      Application& operator=(const Application& app);

      void start(const SekaiEngine::Object::Scence_ptr& initScence);
    };
  } // namespace Core
  
} // namespace SekaiEngine


#endif // _CORE_APPLICATION_
