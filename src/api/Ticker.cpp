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
    SetTargetFPS(m_targetFPS);
}

void SekaiEngine::API::Ticker::nextFrame()
{
    
}

void SekaiEngine::API::Ticker::wait()
{

}