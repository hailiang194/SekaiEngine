#include "./Color.hpp"

SekaiEngine::API::Color::Color(const ::Color& color)
    :m_color(color)
{

}

SekaiEngine::API::Color::Color(const uint32_t& color)
{
    m_color.r = (color >> 24) & 0xff;
    m_color.g = (color >> 16) & 0xff;
    m_color.b = (color >> 8) & 0xff;
    m_color.a = color & 0xff;
}

SekaiEngine::API::Color::Color(const SekaiEngine::API::Color& color)
    :m_color(color.m_color)
{

}

SekaiEngine::API::Color& SekaiEngine::API::Color::operator=(const SekaiEngine::API::Color& color)
{
    m_color = color.m_color;
    return (*this);
}

SekaiEngine::API::Color& SekaiEngine::API::Color::operator=(const ::Color& color)
{
    m_color = color;
    return (*this);
}

SekaiEngine::API::Color& SekaiEngine::API::Color::operator=(const uint32_t& color)
{
    m_color.r = (color >> 24) & 0xff;
    m_color.g = (color >> 16) & 0xff;
    m_color.b = (color >> 8) & 0xff;
    m_color.a = color & 0xff;
    return (*this);
}

const bool SekaiEngine::API::Color::operator==(const SekaiEngine::API::Color& color)
{
    return this->getCode() == color.getCode();
}



SekaiEngine::API::Color::~Color()
{

}