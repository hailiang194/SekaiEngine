#include "asset-manager.h"

namespace SekaiEngine
{
    namespace Core
    {
        TexturesManager::TexturesManager()
            :AssetManager<std::uintptr_t, Texture2D>()
        {

        }

        TexturesManager::TexturesManager(const TexturesManager& manager)
            :AssetManager<std::uintptr_t, Texture2D>(manager)
        {

        }

        TexturesManager& TexturesManager::operator=(const TexturesManager& manager)
        {
            AssetManager<std::uintptr_t, Texture2D>::operator=(manager);

            return (*this);
        }

        TexturesManager::~TexturesManager()
        {

        }

        std::uintptr_t TexturesManager::loadData(const std::string& path)
        {
            const Texture2D* texture = new Texture2D(LoadTexture(path.c_str()));
            if(texture->id == 0)
            {
                throw std::runtime_error("Could not load texture " + path);
            }
            this->insert({texture->id, texture});

            return texture->id;
        }

        void TexturesManager::unload()
        {
            for(auto iter = this->begin(); iter != this->end(); ++iter)
            {
                UnloadTexture(*(iter->second));
                delete (iter->second);
            }

            this->clear();
        }
    } // namespace Core
    
} // namespace SekaiEngine
