#include "./Renderable.hpp"

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

void SekaiEngine::Renderable::Renderable::update()
{
    if(m_parent == nullptr)
    {
        m_absolute = m_relative;
        return;
    }

    m_absolute.updateOffset(API::Vector2D(
        m_parent->offset()->x() + m_parent->scale().x() * m_absolute.offset()->x(),
        m_parent->offset()->y() + m_parent->scale().y() * m_absolute.offset()->y()
    ));
    m_absolute.thick() = m_parent->thick() * m_relative.thick();
    m_absolute.scale() = API::Vector2D(
        m_parent->scale().x() * m_relative.scale().x(),
        m_parent->scale().y() * m_relative.scale().y()
    );

    m_absolute.startAngle() = m_parent->startAngle() + m_relative.startAngle();
    m_absolute.endAngle() = m_parent->endAngle() + m_relative.endAngle();
    m_absolute.origin() = API::Vector2D(
        m_absolute.origin().x() * m_absolute.scale().x(),
        m_absolute.origin().y() * m_absolute.scale().y()
    );
    m_absolute.rotation() = m_parent->rotation() * m_relative.rotation();
}