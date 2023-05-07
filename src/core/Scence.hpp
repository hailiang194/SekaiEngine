#ifndef SEKAI_ENGINE_CORE_SCENCE_HPP
#define SEKAI_ENGINE_CORE_SCENCE_HPP

#include "./Container.hpp"
#include "api/Color.hpp"
#include "api/Camera2D.hpp"

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
            Scence(const Color& color = BLACK, const API::Camera2D& camera = API::Camera2D());
            Scence(const Scence& scence);
            Scence& operator=(const Scence& scence);
            virtual ~Scence();

            virtual void setup();
            virtual void update();
            virtual void render();

            void addObject(GameObject* object, const SCENCE_LAYER& layer = SCENCE_LAYER::CAMERA);
        protected:
            API::Color m_background;
            API::Camera2D m_camera;

            Container m_ctBack;
            Container m_ctCamera;
            Container m_ctFront;
        };
    } // namespace Core
    
} // namespace SekaiEngine


#endif //!SEKAI_ENGINE_CORE_SCENCE_HPP