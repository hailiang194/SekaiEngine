#ifndef _SEKAI_ENGINE_CORE_ASSET_MANAGER_H_
#define _SEKAI_ENGINE_CORE_ASSET_MANAGER_H_

#include "raylib.h"
#include <unordered_map>
#include <string>
#include <cstdint>
#include <stdexcept>

namespace SekaiEngine
{
    namespace Core
    {
        template<class Key, class Value>
        class AssetManager: public std::unordered_map<Key, const Value*>
        {
        public:
            AssetManager();
            AssetManager(const AssetManager& manager);
            AssetManager& operator=(const AssetManager& manager);
            virtual ~AssetManager();

            virtual Key loadData(const std::string& path) = 0;
            virtual void unload() = 0;
        };

        template<class Key, class Value>
        inline AssetManager<Key, Value>::AssetManager()
            :std::unordered_map<Key, const Value*>()
        {

        }

        template<class Key, class Value>
        inline AssetManager<Key, Value>::AssetManager(const AssetManager<Key, Value>& manager)
            :std::unordered_map<Key, const Value*>(manager)
        {

        }

        template<class Key, class Value>
        inline AssetManager<Key, Value>& AssetManager<Key, Value>::operator=(const AssetManager<Key, Value>& manager)
        {
            std::unordered_map<Key, const Value*>::operator=(manager);
            return (*this);
        }

        template<class Key, class Value>
        inline AssetManager<Key, Value>::~AssetManager()
        {
            
        }

        class TexturesManager: public AssetManager<std::uintptr_t, Texture2D>
        {
        public:
            TexturesManager();
            TexturesManager(const TexturesManager& manager);
            TexturesManager& operator=(const TexturesManager& manager);
            virtual ~TexturesManager();

            std::uintptr_t loadData(const std::string& path) override;
            void unload() override;

        };
    } // namespace Core
    
} // namespace SekaiEngine


#endif //_SEKAI_ENGINE_CORE_ASSET_MANAGER_H_