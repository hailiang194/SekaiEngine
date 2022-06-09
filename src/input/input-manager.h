#ifndef _SEKAI_ENGINE_INPUT_MANAGER_H_
#define _SEKAI_ENGINE_INPUT_MANAGER_H_

#include <map>
#include <string>
#include <stdexcept>
#include "input-axis.h"

namespace SekaiEngine
{
    namespace Input
    {
        class InputManager
        {
        public:
            InputManager();
            InputManager(const InputManager& manager);
            InputManager& operator=(const InputManager& manager);
            ~InputManager();

            const std::map<std::string, InputAxis*>& axies() const;
            const std::map<std::string, InputAxis*>& axies();

            void addInputAxis(const std::string& name, InputAxis* axis);

            void destroy();

            void update();

        private:
            std::map<std::string, InputAxis*> m_axies;
            bool m_destroy;
        };

        inline const std::map<std::string, InputAxis*>& InputManager::axies() const
        {
            return m_axies;
        }

        inline const std::map<std::string, InputAxis*>& InputManager::axies()
        {
            return static_cast<const InputManager&>(*this).axies();
        }
    } // namespace Input
    
} // namespace SekaiEngine


#endif //_SEKAI_ENGINE_INPUT_MANAGER_H_