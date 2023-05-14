#include "./Renderable.hpp"



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