#include "scence_manager.h"

namespace SekaiEngine
{
    namespace Core
    {
        ScenceManager::ScenceManager()
            :m_scenceMap(), m_cleaned(true)
        {

        }

        ScenceManager::ScenceManager(const ScenceManager& manager)
            :m_scenceMap(manager.m_scenceMap), m_cleaned(manager.m_cleaned)
        {

        }
        ScenceManager& ScenceManager::operator=(const ScenceManager& manager)
        {
            m_scenceMap = manager.m_scenceMap;
            m_cleaned = manager.m_cleaned;

            return (*this);
        }

        ScenceManager::~ScenceManager()
        {
            clean();
        }

        void ScenceManager::addScence(const std::string& name, Object::Scence* scence)
        {
            if(m_scenceMap.size() > 0 && m_scenceMap.find(name) == m_scenceMap.end())
            {
                throw std::invalid_argument(name + " has been existed");
            }

            if(scence == nullptr)
            {
                throw std::invalid_argument("Can\'t add null-pointer scence");
            }

            m_scenceMap.insert({name, scence});
            m_cleaned = false;
        }

        Object::Scence* ScenceManager::getScence(const std::string& name)
        {
            auto scencePair = m_scenceMap.find(name);
            if(scencePair == m_scenceMap.end())
            {
                return nullptr;
            }

            return scencePair->second;
        }

        void ScenceManager::clean()
        {
            if(m_cleaned)
            {
                return;
            }

            for(auto pair = m_scenceMap.begin(); pair != m_scenceMap.end(); ++pair)
            {
                if(pair->second != nullptr)
                    delete pair->second;
            }

            m_scenceMap.clear();
        }
    } // namespace Core
    
} // namespace SekaiEngine
