#include "./Renderable.hpp"

SekaiEngine::Renderable::RenderableProperties::RenderableProperties()
    : m_color(0x0), m_thick(FILL_THICK), m_scale(), 
    m_startAngle(0.0f), m_endAngle(360.0f), m_segments(36),
    m_origin(), m_rotation(0.0f), m_offset()
{
}

SekaiEngine::Renderable::RenderableProperties::RenderableProperties(const RenderableProperties &properties)
    : m_color(properties.m_color), m_thick(properties.m_thick), m_scale(properties.m_scale), 
    m_startAngle(properties.m_startAngle), m_endAngle(properties.m_endAngle), m_segments(properties.m_segments), 
    m_origin(properties.m_origin), m_rotation(properties.m_rotation), m_offset(properties.m_offset)
{
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
    m_offset = properties.m_offset;

    return (*this);
}

SekaiEngine::Renderable::RenderableProperties::~RenderableProperties()
{
}

SekaiEngine::Renderable::Renderable::Renderable(const RenderableProperties& relative, RenderableProperties* parent)
    :m_relative(relative), m_parent(parent)
{
    update();
}

SekaiEngine::Renderable::Renderable::Renderable(const Renderable& renderable)
    :m_relative(renderable.m_relative), m_parent(renderable.m_parent), m_absolute(renderable.m_absolute)
{

}

SekaiEngine::Renderable::Renderable& SekaiEngine::Renderable::Renderable::operator=(const Renderable& renderable)
{
    m_relative = renderable.m_relative;
    m_parent = renderable.m_parent;
    m_absolute = renderable.m_absolute;

    return (*this);
}

SekaiEngine::Renderable::Renderable::~Renderable()
{

}