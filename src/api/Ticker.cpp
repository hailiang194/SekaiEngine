#include "./Ticker.hpp"

SekaiEngine::API::Ticker::Ticker(const int& targetFPS)
    :m_targetFPS(targetFPS)
{

}

SekaiEngine::API::Ticker::~Ticker()
{

}

void SekaiEngine::API::Ticker::start()
{
#ifdef RAYLIB_API
    SetTargetFPS(m_targetFPS);
#else
#endif
}

void SekaiEngine::API::Ticker::nextFrame()
{
#ifdef RAYLIB_API
#else
#endif
}

void SekaiEngine::API::Ticker::wait()
{
#ifdef RAYLIB_API
#else
#endif
}