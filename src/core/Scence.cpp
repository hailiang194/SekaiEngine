#include <cassert>
#include "./Scence.hpp"

SekaiEngine::Core::Scence::Scence(const Color &color, const Camera2D &camera)
    : m_background(color), m_camera(camera), m_ctBack(), m_ctCamera(), m_ctFront()
{
}

SekaiEngine::Core::Scence::Scence(const SekaiEngine::Core::Scence &scence)
    : m_background(scence.m_background), m_camera(scence.m_camera), m_ctBack(scence.m_ctBack), m_ctCamera(scence.m_ctCamera), m_ctFront(scence.m_ctFront)
{
}

SekaiEngine::Core::Scence &SekaiEngine::Core::Scence::operator=(const SekaiEngine::Core::Scence &scence)
{
    m_background = scence.m_background;
    m_camera = scence.m_camera;
    m_ctBack = scence.m_ctBack;
    m_ctCamera = scence.m_ctCamera;
    m_ctFront = scence.m_ctFront;

    return (*this);
}

SekaiEngine::Core::Scence::~Scence()
{
    m_ctBack.destroy();
    m_ctCamera.destroy();
    m_ctFront.destroy();
}

void SekaiEngine::Core::Scence::setup()
{
    m_ctBack.construct();
    m_ctCamera.construct();
    m_ctFront.construct();
}

void SekaiEngine::Core::Scence::update()
{
    // interact
    m_ctBack.interact();
    m_ctCamera.interact();
    m_ctFront.interact();
    // animate
    m_ctBack.animate();
    m_ctCamera.animate();
    m_ctFront.animate();
    // event
    m_ctBack.event();
    m_ctCamera.event();
    m_ctFront.event();
}

void SekaiEngine::Core::Scence::render()
{
    // render
    BeginDrawing();
    ClearBackground(m_background.get());
    m_ctBack.preRender();
    m_ctBack.render();

    BeginMode2D(m_camera);
    m_ctCamera.preRender();
    m_ctCamera.render();
    EndMode2D();
    
    m_ctFront.preRender();
    m_ctFront.render();
    EndDrawing();
}

void SekaiEngine::Core::Scence::addObject(GameObject *object, const SCENCE_LAYER &layer)
{
    switch (layer)
    {
    case SekaiEngine::Core::SCENCE_LAYER::BACK_CAMERA:
        m_ctBack.addObject(object);
        break;
    case SekaiEngine::Core::SCENCE_LAYER::CAMERA:
        m_ctCamera.addObject(object);
        break;
    case SekaiEngine::Core::SCENCE_LAYER::FRONT_CAMERA:
        m_ctFront.addObject(object);
        break;
    default:
        assert(1 == 1);
        break;
    }
}