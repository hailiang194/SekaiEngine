#include "./Camera2D.hpp"

SekaiEngine::API::Camera2D::Camera2D(const API::Vector2D& offset, const API::Vector2D& target, const float& rotation, const float& zoom)
    :m_offset(offset), m_target(target), m_rotation(rotation), m_zoom(zoom)
{

}

SekaiEngine::API::Camera2D::Camera2D(const ::Camera2D& camera)
    :m_offset(camera.offset), m_target(camera.target), m_rotation(camera.rotation), m_zoom(camera.zoom)
{

}

SekaiEngine::API::Camera2D::Camera2D(const Camera2D& camera)
    :m_offset(camera.m_offset), m_target(camera.m_target), m_rotation(camera.m_rotation), m_zoom(camera.m_zoom)
{

}

SekaiEngine::API::Camera2D& SekaiEngine::API::Camera2D::operator=(const Camera2D& camera)
{
    m_offset = camera.m_offset; 
    m_target = camera.m_target;
    m_rotation = camera.m_rotation;
    m_zoom = camera.m_zoom;

    return (*this);
}

SekaiEngine::API::Camera2D& SekaiEngine::API::Camera2D::operator=(const ::Camera2D& camera)
{
    m_offset = camera.offset; 
    m_target = camera.target;
    m_rotation = camera.rotation;
    m_zoom = camera.zoom;

    return (*this);
}

SekaiEngine::API::Camera2D::~Camera2D()
{

}

void SekaiEngine::API::Camera2D::start()
{
    BeginMode2D(
    {
        m_offset.get(),
        m_target.get(),
        m_rotation,
        m_zoom
    });
}

void SekaiEngine::API::Camera2D::end()
{
    EndMode2D();
}