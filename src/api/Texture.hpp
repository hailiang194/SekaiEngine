#ifndef SEKAI_ENGINE_API_TEXTURE_HPP
#define SEKAI_ENGINE_API_TEXTURE_HPP

#include <string>
#include "./APIConfig.hpp"
#include "./Image.hpp"

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

        private:
            TEXTURE_API* m_texture;
        };

        inline const TEXTURE_API& Texture::get() const
        {
            return *m_texture;
        }

        inline const TEXTURE_API& Texture::get()
        {
            return static_cast<const Texture&>(*this).get();
        }
    } // namespace API
    
} // namespace SekaiEngine


#endif //!SEKAI_ENGINE_API_TEXTURE_HPP