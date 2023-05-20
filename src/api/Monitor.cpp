#include "./Monitor.hpp"

SekaiEngine::API::Monitor::Monitor(const MONITOR_CORE_TYPE& core)
    :m_core(core)
{

}

SekaiEngine::API::Monitor::Monitor(const SekaiEngine::API::Monitor& monitor)
    :m_core(monitor.m_core)
{

}

SekaiEngine::API::Monitor& SekaiEngine::API::Monitor::operator=(const SekaiEngine::API::Monitor& monitor)
{
    m_core = monitor.m_core;
    return (*this);
}

SekaiEngine::API::Monitor::~Monitor()
{

}