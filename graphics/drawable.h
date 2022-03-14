#ifndef _SEKAI_ENGINE_GRAPHIC_DRAWABLE_H_
    #define _SEKAI_ENGINE_GRAPHIC_DRAWABLE_H_

namespace SekaiEngine
{
    namespace Graphic
    {
        class Drawable
        {
        public:
            Drawable();
            Drawable(const Drawable& graphic);
            Drawable& operator=(const Drawable& graphic);
            virtual ~Drawable();

            virtual void render() = 0;
        };
    } // namespace Graphic
    
} // namespace SekaiEngine


#endif //_SEKAI_ENGINE_GRAPHIC_DRAWABLE_H_