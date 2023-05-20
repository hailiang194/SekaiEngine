#include <unordered_map>
#include <fstream>
#include "./Image.hpp"

std::unordered_map<ID_API, IMAGE_API>* images = nullptr;

const ID_API getIDFromRawImage(const IMAGE_API& img)
{
#ifdef RAYLIB_API
    return reinterpret_cast<ID_API>(img.data);
#else
#endif
}

const void unloadRawImage(const IMAGE_API& image)
{
#ifdef RAYLIB_API
            UnloadImage(image);
#else
#endif
}

SekaiEngine::API::Image::Image(const std::string& path)
{
#ifdef RAYLIB_API
    IMAGE_API image = LoadImage(path.c_str());
    if(image.data == nullptr)
    {
        throw std::ifstream::failure("Failed to read Image");
    }
    //ref: https://stackoverflow.com/questions/34291377/converting-a-non-void-pointer-to-uintptr-t-and-vice-versa
    images->insert({getIDFromRawImage(image), image});
    m_image = &images->at(getIDFromRawImage(image));
#else
#endif
}

SekaiEngine::API::Image::Image(const ID_API& id)
{
    auto imgIter = images->find(id);
    if(imgIter == images->end())
    {
        throw std::invalid_argument("Image ID is not available");
    }
    m_image = &images->at(id);
}

SekaiEngine::API::Image::Image(const Image& image)
    :m_image(image.m_image)
{

}

SekaiEngine::API::Image& SekaiEngine::API::Image::operator=(const Image& image)
{
    m_image = image.m_image;
    return (*this);
}

SekaiEngine::API::Image::~Image()
{

}

void SekaiEngine::API::Image::init()
{
    if(images == nullptr)
    {
        images = new std::unordered_map<ID_API, IMAGE_API>();
    }
}

void SekaiEngine::API::Image::unload()
{
    if(images != nullptr)
    {
        for(auto imgIter = images->begin(); imgIter != images->end(); ++imgIter)
        {
            unloadRawImage((*imgIter).second);
        }
        images->clear();
        delete images;
        images = nullptr;
    }
}

const SekaiEngine::API::Image SekaiEngine::API::Image::getScreenShot()
{
#ifdef RAYLIB_API
    IMAGE_API image = LoadImageFromScreen();
    images->insert({getIDFromRawImage(image), image});
    return SekaiEngine::API::Image(getIDFromRawImage(image));
#else
#endif
}