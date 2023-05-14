#ifndef SEKAI_ENGINE_RENDERABLE_RENDERABLE_H
#define SEKAI_ENGINE_RENDERABLE_RENDERABLE_H

#include "RenderableProperties.hpp"

namespace SekaiEngine
{
    namespace Renderable
    {

        class Renderable
        {
        public:
            Renderable(const RenderableProperties& relative, RenderableProperties* parent = nullptr);
            Renderable(const Renderable& renderable);
            Renderable& operator=(const Renderable& renderable);
            virtual ~Renderable();

            const RenderableProperties& relative() const;
            RenderableProperties& relative();

            const RenderableProperties* parent() const;
            const RenderableProperties* parent();

            const RenderableProperties& absolute() const;
            const RenderableProperties& absolute();

            virtual void update();
            virtual bool shouldRender() = 0;
            virtual void render(const bool renderBounding = false) = 0;
        private:
            RenderableProperties m_relative;
            RenderableProperties m_absolute;
            RenderableProperties* m_parent; 
        };

        
        inline const RenderableProperties& Renderable::relative() const
        {
            return m_relative;
        }

        RenderableProperties& Renderable::relative()
        {
            return const_cast<RenderableProperties&>(static_cast<const Renderable&>(*this).relative());
        }

        inline const RenderableProperties* Renderable::parent() const
        {
            return m_parent;
        }

        inline const RenderableProperties* Renderable::parent()
        {
            return static_cast<const Renderable&>(*this).parent();
        }

        inline const RenderableProperties& Renderable::absolute() const
        {
            return m_absolute;
        }

        inline const RenderableProperties& Renderable::absolute()
        {
            return static_cast<const Renderable&>(*this).absolute();
        }
    } // namespace Renderable
    
} // namespace SekaiEngine


#endif //!SEKAI_ENGINE_RENDERABLE_RENDERABLE_H