#ifndef SEKAI_ENGINE_CORE_SCENCE_HPP
#define SEKAI_ENGINE_CORE_SCENCE_HPP

#define DEFAULT_CAMERA {{ 0, 0 }, { 0, 0 }, 0.0f, 1.0f }

#include "raylib.h"
#include "./Container.hpp"

namespace SekaiEngine
{
    namespace Core
    {
        enum class SCENCE_LAYER 
        {
            BACK_CAMERA,
            CAMERA,
            FRONT_CAMERA
        };
        
        class Scence 
        {
        public:
            Scence(const Color& color = BLACK, const Camera2D& camera = DEFAULT_CAMERA);
            Scence(const Scence& scence);
            Scence& operator=(const Scence& scence);
            virtual ~Scence();

            virtual void setup();
            virtual void update();
            virtual void render();

            void addObject(GameObject* object, const SCENCE_LAYER& layer = SCENCE_LAYER::CAMERA);
        protected:
            Color m_background;
            Camera2D m_camera;

            Container m_ctBack;
            Container m_ctCamera;
            Container m_ctFront;
        };
    } // namespace Core
    
} // namespace SekaiEngine


#endif //!SEKAI_ENGINE_CORE_SCENCE_HPP