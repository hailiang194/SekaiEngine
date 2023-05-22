#include <unordered_map>
#include <fstream>
#include "./Texture.hpp"

std::unordered_map<ID_API, TEXTURE_API>* textures = nullptr; 

ID_API getIdByRawTexture(const TEXTURE_API& txt)
{
#ifdef RAYLIB_API
        return static_cast<ID_API>(txt.id);
#else
#endif
}

void unloadRawTexture(const TEXTURE_API& txt)
{
#ifdef RAYLIB_API
    UnloadTexture(txt);
#else
#endif
}

SekaiEngine::API::Texture::Texture(const std::string& path)
{
#ifdef RAYLIB_API
    TEXTURE_API txt = LoadTexture(path.c_str());
    if(txt.id == 0)
    {
        throw std::ifstream::failure("Failed to read Texture");
    }
    textures->insert({getIdByRawTexture(txt), txt});
    m_texture = &textures->at(getIdByRawTexture(txt));
#else
#endif
}

SekaiEngine::API::Texture::Texture(const ID_API& id)
{
    auto iter = textures->find(id);
    if(iter == textures->end())
    {
        throw std::invalid_argument("Texture ID is not available");
    }
    m_texture = &iter->second;
}

SekaiEngine::API::Texture::Texture(const Texture& texture)
    :m_texture(texture.m_texture)
{

}

SekaiEngine::API::Texture& SekaiEngine::API::Texture::operator=(const Texture& texture)
{
    m_texture = texture.m_texture;
    return (*this);
}

SekaiEngine::API::Texture::~Texture()
{

}

void SekaiEngine::API::Texture::init()
{
    if(textures == nullptr)
    {
        textures = new std::unordered_map<ID_API, TEXTURE_API>();
    }
}

void SekaiEngine::API::Texture::unload()
{
    if(textures != nullptr)
    {
        for(auto iter = textures->begin(); iter != textures->end(); ++iter)
        {
            unloadRawTexture(iter->second);
        }
        textures->clear();
    }
    delete textures;
    textures = nullptr;
}