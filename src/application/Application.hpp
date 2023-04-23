#ifndef SEKAI_ENGINE_APPLICATION_APPLICATION_HPP
#define SEKAI_ENGINE_APPLICATION_APPLICATION_HPP

#include "api/Monitor.hpp"
#include "core/Scence.hpp"
#include <string>
#include <functional>
#include <iostream>

#ifndef _DEBUG
#define DEFAULT_EXCEPTION_CALLBACK [](const std::exception& e) { std::cout << e.what() << std::endl; exit(EXIT_FAILURE);}
#else
#define DEFAULT_EXCEPTION_CALLBACK [](const std::exception& e) { throw e;}
#endif

namespace SekaiEngine
{
    namespace Application
    {
        class Application
        {
        public:
            Application(const std::string& title = "SekaiEngineGame", const int& width = API::Monitor::currentMonitor().width(), const int& height = API::Monitor::currentMonitor().height());
            ~Application();
            void addScrence(const std::string& name, Core::Scence* scence);
            void start(const std::string& initScenceName, std::function<void(const std::exception&)> exceptionCallback = DEFAULT_EXCEPTION_CALLBACK);
        };
    } // namespace Application
    
} // namespace SekaiEngine


#endif //!SEKAI_ENGINE_APPLICATION_APPLICATION_HPP