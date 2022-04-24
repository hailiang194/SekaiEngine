#ifndef _SEKAI_ENGINE_CORE_SCENCE_MANAGER_H_
    #define _SEKAI_ENGINE_CORE_SCENCE_MANAGER_H_

#include <unordered_map>
#include <stdexcept>
#include "../objects/scence.h"

namespace SekaiEngine
{
    namespace Core
    {
        class ScenceManager
        {
        public:
            ScenceManager();
            ScenceManager(const ScenceManager& manager);
            ScenceManager& operator=(const ScenceManager& manager);
            ~ScenceManager();

            void addScence(const std::string& name, Object::Scence* scence);
            Object::Scence* getScence(const std::string& name);

            void clean();
        private:
            std::unordered_map<std::string, Object::Scence*> m_scenceMap;
            bool m_cleaned;
        };
    } // namespace Core
    
} // namespace SekaiEngine


#endif