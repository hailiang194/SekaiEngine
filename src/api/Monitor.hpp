#ifndef SEKAI_ENGINE_API_MONITOR_HPP
#define SEKAI_ENGINE_API_MONITOR_HPP

#include <cstddef>
#include <string>
#include "raylib.h"
#include "./Vector.hpp"

#define MONITOR_CORE_TYPE int

namespace SekaiEngine
{
    namespace API
    {
        class Monitor
        {
        public:
            Monitor(MONITOR_CORE_TYPE core);
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
            return GetMonitorWidth(m_core);
        }

        inline const int Monitor::width()
        {
            return static_cast<const Monitor&>(*this).width();
        }

        inline const int Monitor::height() const
        {
            return GetMonitorHeight(m_core);
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
            return (API::Vector2D)GetMonitorPosition(m_core);
        }

        inline const API::Vector2D Monitor::position()
        {
            return static_cast<const Monitor&>(*this).position();
        }

        inline const int Monitor::refreshRate() const
        {
            return GetMonitorRefreshRate(m_core);
        }

        inline const int Monitor::refreshRate()
        {
            return static_cast<const Monitor&>(*this).refreshRate();
        }

        inline const std::string Monitor::name() const
        {
            const char* name = GetMonitorName(m_core);
            return std::string(name);
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
            return Monitor(GetCurrentMonitor());
        }

        inline const std::size_t Monitor::count()
        {
            return static_cast<const std::size_t>(GetMonitorCount());
        }
    } // namespace API
    
} // namespace SekaiEngine


#endif //!SEKAI_ENGINE_API_MONITOR_HPP