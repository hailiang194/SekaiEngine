#ifndef SEKAI_ENGINE_API_IMAGE_HPP
#define SEKAI_ENGINE_API_IMAGE_HPP

#include <string>
#include "raylib.h"

namespace SekaiEngine
{
    namespace API
    {
        class Image
        {
        public:
            Image(const std::string& path);
            Image(const std::size_t& id);
            Image(const Image& image);
            Image& operator=(const Image& image);
            ~Image();

        private:
            ::Image* m_image;

        };
    } // namespace API
    
} // namespace SekaiEngine


#endif //!SEKAI_ENGINE_API_IMAGE_HPP