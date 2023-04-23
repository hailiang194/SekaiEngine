#ifndef SEKAI_ENGINE_APPLICATION_GAME_HPP
#define SEKAI_ENGINE_APPLICATION_GAME_HPP

#include <string>

namespace SekaiEngine
{
    namespace Application
    {
        class Game
        {
        public:
            static Game* instance();
            static void init(const std::string& title, const int& width, const int& height);
            static void deleteInstance();
        private:
            Game();
            ~Game();

            static Game *g_instance;
        };
    } // namespace Application
    
} // namespace SekaiEngine


#endif //!SEKAI_ENGINE_APPLICATION_GAME_HPP