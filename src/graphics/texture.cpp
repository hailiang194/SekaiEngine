#include "texture.h"

namespace SekaiEngine
{
    namespace Graphic
    {
        EngineTexture::EngineTexture(const std::string& path, const float& scaleX, const float& scaleY, const Transform2D& transform)
            :Graphic(transform), m_scaleX(scaleX), m_scaleY(scaleY)
        {
            auto id = SekaiEngine::Core::Game::textures().loadData(path);
            m_texture = SekaiEngine::Core::Game::textures().at(id);

            m_source = Rectangle(SekaiEngine::Utility::Vector2D(), m_texture->width, m_texture->height);
        }

        EngineTexture::EngineTexture(const std::uintptr_t& id, const float& scaleX, const float& scaleY, const Transform2D& transform)
            :Graphic(transform), m_scaleX(scaleX), m_scaleY(scaleY)
        {
            m_texture = SekaiEngine::Core::Game::textures().at(id);
            m_source = Rectangle(SekaiEngine::Utility::Vector2D(), m_texture->width, m_texture->height);
        }

        EngineTexture::EngineTexture(const std::string& path, const Rectangle& source, const float& scaleX, const float& scaleY, const Transform2D& transform)
                :Graphic(transform), m_scaleX(scaleX), m_scaleY(scaleY), m_source(source)
        
        {
            auto id = SekaiEngine::Core::Game::textures().loadData(path);
            m_texture = SekaiEngine::Core::Game::textures().at(id);
        }

        EngineTexture::EngineTexture(const std::uintptr_t& id, const Rectangle& source, const float& scaleX, const float& scaleY, const Transform2D& transform)
                :Graphic(transform), m_scaleX(scaleX), m_scaleY(scaleY), m_source(source)
        
        {
            m_texture = SekaiEngine::Core::Game::textures().at(id);
        }
            

        EngineTexture::EngineTexture(const EngineTexture& texture)
            :Graphic(texture), m_texture(texture.m_texture), m_scaleX(texture.m_scaleX), m_scaleY(texture.m_scaleY), m_source(texture.m_source)
        {

        }

        EngineTexture& EngineTexture::operator=(const EngineTexture& texture)
        {
            Graphic::operator=(texture);
            m_texture = texture.m_texture;
            m_scaleX = texture.m_scaleX;
            m_scaleY = texture.m_scaleY;
            m_source = texture.m_source;

            return (*this);
        }

        EngineTexture::~EngineTexture()
        {
        }

        const Transform2D EngineTexture::drawGraphic(const Transform2D* parent)
        {
            Transform2D transformed = (parent == nullptr) ? m_self : getTransformedValues(*parent, m_self);

            DrawTexturePro(
                *m_texture,
                {m_source.position().x(), m_source.position().y(), m_source.width(), m_source.height()},
                {transformed.position().x(), transformed.position().y(), 
                 transformed.scale() * m_scaleX * m_source.width(),
                 transformed.scale() * m_scaleY * m_source.height()
                },
                transformed.origin().toRaylibVector(),
                transformed.rotation(),
                transformed.color()
            );
            
            return transformed;
        }
    } // namespace Graphic
    
} // namespace SekaiEngine
