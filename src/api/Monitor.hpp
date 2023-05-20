#ifndef SEKAI_ENGINE_API_MONITOR_HPP
#define SEKAI_ENGINE_API_MONITOR_HPP

#include <cstddef>
#include <string>
#include "APIConfig.hpp"
#include "./Vector.hpp"


namespace SekaiEngine
{
    namespace API
    {
        class Monitor
        {
        public:
            Monitor(const MONITOR_CORE_TYPE& core);
            Monitor(const Monitor& monitor);
            Monitor& operator=(const Monitor& monitor);
            ~Monitor();

            const int width() const;
            const int width();

            const int height() const;
            const int height();

            const API::Vector2D position() const;
            const API::Vector2D position();

            const int refreshRate() const;
            const int refreshRate();

            const std::string name() const;
            const std::string name();

            const MONITOR_CORE_TYPE& get() const;
            const MONITOR_CORE_TYPE& get();

            static const Monitor currentMonitor();
            static const std::size_t count();
        private:
            MONITOR_CORE_TYPE m_core;
        };

        inline const int Monitor::width() const
        {
#ifdef RAYLIB_API
            return GetMonitorWidth(m_core);
#else
#endif
        }

        inline const int Monitor::width()
        {
            return static_cast<const Monitor&>(*this).width();
        }

        inline const int Monitor::height() const
        {
#ifdef RAYLIB_API
            return GetMonitorHeight(m_core);
#else
#endif
        }

        inline const int Monitor::height()
        {
            return static_cast<const Monitor&>(*this).height();
        }

        inline const MONITOR_CORE_TYPE& Monitor::get() const
        {
            return m_core;
        }

        inline const API::Vector2D Monitor::position() const
        {
#ifdef RAYLIB_API
            return (API::Vector2D)GetMonitorPosition(m_core);
#else
#endif
        }

        inline const API::Vector2D Monitor::position()
        {
            return static_cast<const Monitor&>(*this).position();
        }

        inline const int Monitor::refreshRate() const
        {
#ifdef RAYLIB_API
            return GetMonitorRefreshRate(m_core);
#else
#endif
        }

        inline const int Monitor::refreshRate()
        {
            return static_cast<const Monitor&>(*this).refreshRate();
        }

        inline const std::string Monitor::name() const
        {
#ifdef RAYLIB_API
            const char* name = GetMonitorName(m_core);
            return std::string(name);
#else
#endif
        }

        inline const std::string Monitor::name()
        {
            return static_cast<const Monitor&>(*this).name();
        }

        inline const MONITOR_CORE_TYPE& Monitor::get()
        {
            return static_cast<const Monitor&>(*this).get();
        }

        inline const Monitor Monitor::currentMonitor()
        {
#ifdef RAYLIB_API
            MONITOR_CORE_TYPE current = GetCurrentMonitor();
#else
#endif
            return Monitor(current);
        }

        inline const std::size_t Monitor::count()
        {
#ifdef RAYLIB_API
            return static_cast<const std::size_t>(GetMonitorCount());
#else
#endif
        }
    } // namespace API
    
} // namespace SekaiEngine


#endif //!SEKAI_ENGINE_API_MONITOR_HPP