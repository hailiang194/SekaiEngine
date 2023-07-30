#ifndef SEKAI_ENGINE_API_TEXTURE_HPP
#define SEKAI_ENGINE_API_TEXTURE_HPP

#include <string>
#include "./APIConfig.hpp"
#include "./Image.hpp"
#include "renderable/RenderableProperties.hpp"
#include "Shape.hpp"

namespace SekaiEngine
{
    namespace API
    {
        class Texture
        {
        public:
            Texture(const std::string& path);
            Texture(const ID_API& id);
            Texture(const Texture& texture);
            Texture& operator=(const Texture& texture);
            ~Texture();

            static void init();
            static void unload();

            const TEXTURE_API& get() const;
            const TEXTURE_API& get();

            const bool isRenderable(const Renderable::RenderableProperties& properties, const Shape& shape) const;
            const bool isRenderable(const Renderable::RenderableProperties& properties, const Shape& shape);
            void render(const Renderable::RenderableProperties properties);

        private:
            TEXTURE_API* m_texture;
        };

        class RenderableTexture
        {
        public:
            RenderableTexture(const Texture& texture);
            RenderableTexture(const Texture& texture, const Rectangle& coordinate);
            RenderableTexture(const RenderableTexture& texture);
            RenderableTexture& operator=(const RenderableTexture& texture);
            ~RenderableTexture();

            const bool isRenderable(const Renderable::RenderableProperties& properties, const Shape& shape) const;
            const bool isRenderable(const Renderable::RenderableProperties& properties, const Shape& shape);

            void render(const Renderable::RenderableProperties properties);

            const Texture& texture() const;
            const Texture& texture();

            const Rectangle& coordinate() const;
            Rectangle& coordinate();
        private:
            Texture m_texture;
            Rectangle m_coordinate; //texture coordinate
        };

        inline const TEXTURE_API& Texture::get() const
        {
            return *m_texture;
        }

        inline const TEXTURE_API& Texture::get()
        {
            return static_cast<const Texture&>(*this).get();
        }

        inline const bool Texture::isRenderable(const Renderable::RenderableProperties& properties, const Shape& shape)
        {
            return const_cast<const Texture&>(*this).isRenderable(properties, shape);
        }

        inline const bool RenderableTexture::isRenderable(const Renderable::RenderableProperties& properties, const Shape& shape)
        {
            return const_cast<const RenderableTexture&>(*this).isRenderable(properties, shape);
        }

        inline const Texture& RenderableTexture::texture() const
        {
            return m_texture;
        }

        inline const Texture& RenderableTexture::texture()
        {
            return const_cast<const RenderableTexture&>(*this).texture();
        }

        inline const Rectangle& RenderableTexture::coordinate() const
        {
            return m_coordinate;
        }

        inline Rectangle& RenderableTexture::coordinate()
        {
            return const_cast<Rectangle&>(static_cast<const RenderableTexture&>(*this).coordinate());
        }

    } // namespace API
    
} // namespace SekaiEngine


#endif //!SEKAI_ENGINE_API_TEXTURE_HPP