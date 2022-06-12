#ifndef _SEKAI_ENGINE_GRAPHIC_H_
    #define _SEKAI_ENGINE_GRAPHIC_H_

#include "transform2d.h"

namespace SekaiEngine
{
    namespace Graphic
    {
        class Graphic
        {
        public:
            Graphic(const Transform2D& self = Transform2D(), Transform2D* parent = nullptr);
            Graphic(const Graphic& graphic);
            Graphic& operator=(const Graphic& graphic);
            virtual ~Graphic();

            const Transform2D& transform() const;
            Transform2D& transform();

            const Transform2D& parent() const;
            const Transform2D& parent();

            void changeParent(Transform2D* parent);

            const Transform2D& transformed() const;
            const Transform2D& transformed();

            void update();
            void render();

        protected:
            virtual void computeTransform_();
            virtual void render_() = 0;

            Transform2D m_self;
            Transform2D* m_parent;
            Transform2D m_transformed;
        };

        inline const Transform2D& Graphic::transform() const
        {
            return m_self;
        }

        inline Transform2D& Graphic::transform()
        {
            return const_cast<Transform2D&>(static_cast<const Graphic&>(*this).transform());
        }

        inline const Transform2D& Graphic::parent() const
        {
            return *m_parent;
        }

        inline const Transform2D& Graphic::parent()
        {
            return static_cast<const Graphic&>(*this).parent();
        }

        inline void Graphic::changeParent(Transform2D* parent)
        {
            m_parent = parent;
            computeTransform_();
        }

        inline const Transform2D& Graphic::transformed() const
        {
            return m_transformed;
        }

        inline const Transform2D& Graphic::transformed()
        {
            return m_transformed;
        }
    } // namespace Graphic
    
} // namespace SekaiEngine


#endif