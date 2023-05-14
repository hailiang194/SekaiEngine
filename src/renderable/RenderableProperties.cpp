#include "./RenderableProperties.hpp"

SekaiEngine::Renderable::RenderableProperties::RenderableProperties(API::Vector2D* offset)
    : m_color(0x0), m_thick(FILL_THICK), m_scale(1.0f, 1.0f), 
    m_startAngle(0.0f), m_endAngle(360.0f), m_segments(36),
    m_origin(), m_rotation(0.0f), m_standaloneOffset(offset == nullptr)
{
    if(m_standaloneOffset)
    {
        m_offset = new API::Vector2D();
    }
    else
    {
        m_offset = offset;
    }
}

SekaiEngine::Renderable::RenderableProperties::RenderableProperties(const RenderableProperties &properties)
    : m_color(properties.m_color), m_thick(properties.m_thick), m_scale(properties.m_scale), 
    m_startAngle(properties.m_startAngle), m_endAngle(properties.m_endAngle), m_segments(properties.m_segments), 
    m_origin(properties.m_origin), m_rotation(properties.m_rotation), m_standaloneOffset(properties.m_standaloneOffset)
{
    if(m_standaloneOffset && m_offset == nullptr)
    {
        m_offset = new API::Vector2D(*(properties.m_offset));
    }
    else
    {
        m_offset = properties.m_offset;
    }
}

SekaiEngine::Renderable::RenderableProperties &SekaiEngine::Renderable::RenderableProperties::operator=(const RenderableProperties &properties)
{
    m_color = properties.m_color; 
    m_thick = properties.m_thick;
    m_scale = properties.m_scale;
    m_startAngle = properties.m_startAngle;
    m_endAngle = properties.m_endAngle;
    m_segments = properties.m_segments; 
    m_origin = properties.m_origin;
    m_rotation = properties.m_rotation;

    if(m_standaloneOffset && m_offset == nullptr)
    {
        m_offset = new API::Vector2D(*(properties.m_offset));
    }
    else
    {
        *m_offset = *properties.m_offset;
    }
    return (*this);
}

SekaiEngine::Renderable::RenderableProperties::~RenderableProperties()
{
    if(m_standaloneOffset)
        delete m_offset;

    m_offset = nullptr;
}