#include "transform2d.h"

SekaiEngine::Graphic::Transform2D::Transform2D(const Utility::Vector2D& position, const float& scale, const Utility::Vector2D& origin, const float& rotation, const Color& color)
	:m_position(position), m_scale(scale), m_origin(origin), m_rotation(rotation), m_color(color)
{
}

SekaiEngine::Graphic::Transform2D::Transform2D(const Transform2D& transform)
	: m_position(transform.m_position), m_scale(transform.m_scale), m_origin(transform.m_origin), m_rotation(transform.m_rotation), m_color(transform.m_color)
{
}

SekaiEngine::Graphic::Transform2D& SekaiEngine::Graphic::Transform2D::operator=(const Transform2D& transfrom)
{
	m_position = transfrom.m_position;
	m_scale = transfrom.m_scale;
	m_origin = transfrom.m_origin;
	m_rotation = transfrom.m_rotation;
	m_color = transfrom.m_color;

	return (*this);
}

SekaiEngine::Graphic::Transform2D::~Transform2D()
{
}
