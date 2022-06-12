#include "transform2d.h"

namespace SekaiEngine
{
	namespace Graphic
	{
		Transform2D::Transform2D(const Utility::Vector2D &position, const float &scale, const Utility::Vector2D &origin, const float &rotation, const Color &color, const int& lineThick)
			: m_position(position), m_scale(scale), m_origin(origin), m_rotation(rotation), m_color(color), m_lineThick(lineThick)
		{
		}

		Transform2D::Transform2D(const Transform2D &transform)
			: m_position(transform.m_position), m_scale(transform.m_scale), m_origin(transform.m_origin), m_rotation(transform.m_rotation), m_color(transform.m_color), m_lineThick(transform.m_lineThick)
		{
		}

		Transform2D &Transform2D::operator=(const Transform2D &transfrom)
		{
			m_position = transfrom.m_position;
			m_scale = transfrom.m_scale;
			m_origin = transfrom.m_origin;
			m_rotation = transfrom.m_rotation;
			m_color = transfrom.m_color;
			m_lineThick = transfrom.m_lineThick;

			return (*this);
		}

		Transform2D::~Transform2D()
		{
		}

		const Transform2D getTransformedValues(const Transform2D& parent, const Transform2D& self)
		{
			Transform2D tranformed;

			tranformed.position() = parent.position() + self.position();
			tranformed.scale() = parent.scale() * self.scale();
			tranformed.origin() = self.origin() * tranformed.scale();
			tranformed.rotation() = parent.rotation() + self.rotation();

			tranformed.color().r = (unsigned char)(parent.color().r / 255.0f * self.color().r);
			tranformed.color().g = (unsigned char)(parent.color().g / 255.0f * self.color().g);
			tranformed.color().b = (unsigned char)(parent.color().b / 255.0f * self.color().b);
			tranformed.color().a = (unsigned char)(parent.color().a / 255.0f * self.color().a);

			return tranformed;
		}
	} // namespace Graphic

} // SekaiEngine
