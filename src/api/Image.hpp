#ifndef SEKAI_ENGINE_API_IMAGE_HPP
#define SEKAI_ENGINE_API_IMAGE_HPP

#include <string>
#include "./APIConfig.hpp"

namespace SekaiEngine
{
    namespace API
    {
        class Image
        {
        public:
            Image(const std::string& path);
            Image(const ID_API& id);
            Image(const Image& image);
            Image& operator=(const Image& image);
            ~Image();

            const IMAGE_API& get() const;
            const IMAGE_API& get();

            const bool exportImage(const std::string& path) const;
            const bool exportImage(const std::string& path);

            static void init();
            static void unload();
            static const Image getScreenShot();

        private:
            IMAGE_API* m_image;
        };

        inline const IMAGE_API& Image::get() const
        {
            return *m_image;
        }

        inline const IMAGE_API& Image::get()
        {
            return static_cast<const Image&>(*this).get();
        }

        inline const bool Image::exportImage(const std::string& path) const
        {
#ifdef RAYLIB_API
            return ExportImage(*m_image, path.c_str());
#else

#endif
        }

        inline const bool Image::exportImage(const std::string& path)
        {
            return static_cast<const Image&>(*this).exportImage(path);
        }
    } // namespace API
    
} // namespace SekaiEngine


#endif //!SEKAI_ENGINE_API_IMAGE_HPP