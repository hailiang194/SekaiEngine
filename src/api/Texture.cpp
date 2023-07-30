#include <unordered_map>
#include <fstream>
#include "./Texture.hpp"
#include "./DrawGraphic.hpp"

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

const bool SekaiEngine::API::Texture::isRenderable(const Renderable::RenderableProperties& properties, const Shape& shape) const
{

    return true;
}

void SekaiEngine::API::Texture::render(const Renderable::RenderableProperties properties)
{

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

SekaiEngine::API::RenderableTexture::RenderableTexture(const Texture& texture)
    :m_texture(texture), m_coordinate({0.0f, 0.0f}, static_cast<const float>(texture.get().width), static_cast<const float>(texture.get().height))
{

}

SekaiEngine::API::RenderableTexture::RenderableTexture(const Texture& texture, const Rectangle& coordinate)
    :m_texture(texture), m_coordinate(coordinate)
{

}

SekaiEngine::API::RenderableTexture::RenderableTexture(const RenderableTexture& texture)
    :m_texture(texture.m_texture), m_coordinate(texture.m_coordinate)
{

}

SekaiEngine::API::RenderableTexture& SekaiEngine::API::RenderableTexture::operator=(const RenderableTexture& texture)
{
    m_texture = texture.m_texture;
    m_coordinate = texture.m_coordinate;
    return (*this);
}

SekaiEngine::API::RenderableTexture::~RenderableTexture()
{

}

const bool SekaiEngine::API::RenderableTexture::isRenderable(const Renderable::RenderableProperties& properties, const Shape& shape) const
{
    Rectangle bounding(properties.offset(), m_coordinate.width() * properties.scale().x(), m_coordinate.height() * properties.scale().y());
    return bounding.intersect(shape);
}

void SekaiEngine::API::RenderableTexture::render(const Renderable::RenderableProperties properties)
{
    Rectangle dest(properties.offset(), m_coordinate.width() * properties.scale().x(), m_coordinate.height() * properties.scale().y());
    API::drawTexture(m_texture, m_coordinate, dest, properties.origin(), properties.rotation(), properties.color());
}