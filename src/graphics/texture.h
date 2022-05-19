#ifndef _SEKAI_ENGINE_GRAPHIC_TEXTURE_H_
#define _SEKAI_ENGINE_GRAPHIC_TEXTURE_H_

#include "raylib.h"
#include "../core/game.h"
#include "../shapes/rectangle.h"
#include "graphic.h"
#include <string>

namespace SekaiEngine
{
    namespace Graphic
    {
        class EngineTexture: public Graphic
        {
        public:
            EngineTexture(const std::string& path, const float& scaleX = 1.0f, const float& scaleY = 1.0f, const Transform2D& transform = Transform2D());
            EngineTexture(const std::uintptr_t& id, const float& scaleX = 1.0f, const float& scaleY = 1.0f, const Transform2D& transform = Transform2D());
            EngineTexture(const std::string& path, const Rectangle& source, const float& scaleX = 1.0f, const float& scaleY = 1.0f, const Transform2D& transform = Transform2D());
            EngineTexture(const std::uintptr_t& id, const Rectangle& source, const float& scaleX = 1.0f, const float& scaleY = 1.0f, const Transform2D& transform = Transform2D());
            EngineTexture(const EngineTexture& texture);
            EngineTexture& operator=(const EngineTexture& texture);
            virtual ~EngineTexture();

            const Texture2D& texture() const;
            const Texture2D& texture();

            const float& scaleX() const;
            float& scaleX();

            const float& scaleY() const;
            float& scaleY();

            const Rectangle& source() const;
            Rectangle& source(); 

            const Transform2D drawGraphic(const Transform2D* parent = nullptr) override;
        protected:
            const Texture2D* m_texture;
            Rectangle m_source;
            float m_scaleX;
            float m_scaleY;
            
        };

        inline const Texture2D& EngineTexture::texture() const
        {
            return *m_texture;
        }

        inline const Texture2D& EngineTexture::texture()
        {
            return static_cast<const Texture2D&>((*this).texture());
        }

        inline const float& EngineTexture::scaleX() const
        {
            return m_scaleX;
        }

        inline float& EngineTexture::scaleX()
        {
            return const_cast<float&>(static_cast<const EngineTexture&>(*this).scaleX());
        }

        inline const float& EngineTexture::scaleY() const
        {
            return m_scaleY;
        }

        inline float& EngineTexture::scaleY()
        {
            return const_cast<float&>(static_cast<const EngineTexture&>(*this).scaleY());
        }

        inline const Rectangle& EngineTexture::source() const
        {
            return m_source;
        }

        inline Rectangle& EngineTexture::source()
        {
            return const_cast<Rectangle&>(static_cast<const EngineTexture&>(*this).source());
        }
    } // namespace Graphic
    
} // namespace SekaiEngine


#endif //_SEKAI_ENGINE_GRAPHIC_TEXTURE_H_