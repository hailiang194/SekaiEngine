#ifndef _SEKAI_ENGINE_GRAPHIC_H_
    #define _SEKAI_ENGINE_GRAPHIC_H_

namespace SekaiEngine
{
    namespace Graphic
    {
        class Graphic
        {
        public:
            Graphic();
            Graphic(const Graphic& graphic);
            Graphic& operator=(const Graphic& graphic);
            virtual ~Graphic();
        };
    } // namespace Graphic
    
} // namespace SekaiEngine


#endif