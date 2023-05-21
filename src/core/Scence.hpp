#ifndef SEKAI_ENGINE_CORE_SCENCE_HPP
#define SEKAI_ENGINE_CORE_SCENCE_HPP

#include <cassert>
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
            virtual void destroy();

            void addObject(GameObject* object, const SCENCE_LAYER& layer = SCENCE_LAYER::CAMERA);

            const API::Color& background() const;
            API::Color& background();

            const API::Camera2D& camera() const;
            API::Camera2D& camera();
#ifdef TEST_RUN
            const Container& getLayer(const SCENCE_LAYER& layer) const;
            const Container& getLayer(const SCENCE_LAYER& layer);
#endif
        protected:
            API::Color m_background;
            API::Camera2D m_camera;

            Container m_ctBack;
            Container m_ctCamera;
            Container m_ctFront;

            void _beginRender();
            void _endRender();
        };

        inline const API::Color& Scence::background() const
        {
            return m_background;
        }

        inline API::Color& Scence::background()
        {
            return const_cast<API::Color&>(static_cast<const Scence&>(*this).background());
        }

        inline const API::Camera2D& Scence::camera() const
        {
            return m_camera;
        }

        inline API::Camera2D& Scence::camera()
        {
            return const_cast<API::Camera2D&>(static_cast<const Scence&>(*this).camera());
        }

#ifdef TEST_RUN
        inline const Container& Scence::getLayer(const SCENCE_LAYER& layer) const
        {
            switch (layer)
            {
            case SCENCE_LAYER::BACK_CAMERA:
                return m_ctBack;
            case SCENCE_LAYER::CAMERA:
                return m_ctCamera;
            case SCENCE_LAYER::FRONT_CAMERA:
                return m_ctFront;
            default:
                assert(1 == 1 && "Invalid layer");
                break;
            }

            //just for warning C4715
            return m_ctBack;
        }

        inline const Container& Scence::getLayer(const SCENCE_LAYER& layer)
        {
            return static_cast<const Scence&>(*this).getLayer(layer);
        }
#endif
    } // namespace Core
    
} // namespace SekaiEngine


#endif //!SEKAI_ENGINE_CORE_SCENCE_HPP