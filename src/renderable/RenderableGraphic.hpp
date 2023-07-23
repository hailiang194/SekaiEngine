#ifndef SEKAI_ENGINE_RENDERABLE_RENDERALE_GRAPHIC_HPP
#define SEKAI_ENGINE_RENDERABLE_RENDERALE_GRAPHIC_HPP

#include "RenderableProperties.hpp"
#include "api/Shape.hpp"

namespace SekaiEngine
{
    namespace Renderable
    {
        class RenderableGraphic 
        {
        public:
            RenderableGraphic();
            RenderableGraphic(const RenderableGraphic& graphic);
            RenderableGraphic& operator=(const RenderableGraphic& graphic);
            virtual ~RenderableGraphic();

            virtual const bool isRenderable(const RenderableProperties& properties, const API::Shape* boundingShape) = 0;
            virtual void render(const RenderableProperties& properties) = 0;
        };
    } // namespace Renderable
    
} // namespace SekaiEngine


#endif //SEKAI_ENGINE_RENDERABLE_RENDERALE_GRAPHIC_HPP