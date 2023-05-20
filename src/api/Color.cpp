#include "./Color.hpp"

#ifdef RAYLIB_API
#define RAW_TO_COLOR(color) \
    m_r = color.r; \
    m_g = color.g; \
    m_b = color.b; \
    m_a = color.a; 

#else
#endif

SekaiEngine::API::Color::Color(const COLOR_API& color)
{
    RAW_TO_COLOR(color)
}

SekaiEngine::API::Color::Color(const uint32_t& color)
{
    m_r = (color >> 24) & 0xff;
    m_g = (color >> 16) & 0xff;
    m_b = (color >> 8) & 0xff;
    m_a = color & 0xff;
}

SekaiEngine::API::Color::Color(const SekaiEngine::API::Color& color)
    :m_r(color.m_r), m_g(color.m_g), m_b(color.m_b), m_a(color.m_a)
{

}

SekaiEngine::API::Color& SekaiEngine::API::Color::operator=(const SekaiEngine::API::Color& color)
{
    m_r = color.m_r;
    m_g = color.m_g; 
    m_b = color.m_b;
    m_a = color.m_a;

    return (*this);
}

SekaiEngine::API::Color& SekaiEngine::API::Color::operator=(const COLOR_API& color)
{
    RAW_TO_COLOR(color)
    return (*this);
}

SekaiEngine::API::Color& SekaiEngine::API::Color::operator=(const uint32_t& color)
{
    m_r = (color >> 24) & 0xff;
    m_g = (color >> 16) & 0xff;
    m_b = (color >> 8) & 0xff;
    m_a = color & 0xff;
    
    return (*this);
}

const bool SekaiEngine::API::Color::operator==(const SekaiEngine::API::Color& color)
{
    return this->getCode() == color.getCode();
}



SekaiEngine::API::Color::~Color()
{

}