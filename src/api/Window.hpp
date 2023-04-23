#ifndef SEKAI_ENGINE_API_WINDOW_HPP
#define SEKAI_ENGINE_API_WINDOW_HPP

#include "./Monitor.hpp"
#include "api/Vector2D.hpp"
#include <string>
#include <cassert>

#define STATE_FLAG_TYPE unsigned int

namespace SekaiEngine
{
    namespace API
    {
#ifdef PLATFORM_DESKTOP
        enum class WindowState 
        {
            MAXIMIZE,
            MINIMIZE,
            RESTORE
        };
#endif

        class Window
        {
        public:
            Window(const int &width, const int &height, const std::string &title);
            ~Window();

            const bool isReady();
            const bool shouldClose();
            const bool isFullScreen();
            const bool isResized();
            const bool isState(const STATE_FLAG_TYPE& flag);
            void clearState(const STATE_FLAG_TYPE& flag);
            void setMonitor(const Monitor &monitor);
            void setSize(const int &width, const int &height);
            const int getWidth();
            const int getHeight();
            const API::Vector2D position();
            void* windowHandle();

            const std::string& title() const;
            const std::string& title();
#ifdef PLATFORM_DESKTOP
            const bool isHidden();
            const bool isMaximized();
            const bool isMinimized();
            const bool isForcused();
            void setState(const STATE_FLAG_TYPE& flag);
            void toggleFullscreen();
            void setWindowState(const WindowState& state);
            void setTitle(const std::string& title);
            //Set Icon [Waiting for Image API]
            void setPosition(const API::Vector2D& position);
            void setMinSize(const int& width, const int& height);
            void setOpacity(const float& opacity);
#endif
        private:
            std::string m_title;
        };

        inline const bool Window::isReady()
        {
            return IsWindowReady();
        }

        inline const bool Window::shouldClose()
        {
            return WindowShouldClose();
        }

        inline const bool Window::isFullScreen()
        {
            return IsWindowFullscreen();
        }

        inline const bool Window::isResized()
        {
            return IsWindowResized();
        }

        inline const bool Window::isState(const STATE_FLAG_TYPE& flag)
        {
            return IsWindowState(flag);
        }

        inline void Window::clearState(const STATE_FLAG_TYPE& flag)
        {
            ClearWindowState(flag);
        }

        inline void Window::setMonitor(const Monitor &monitor)
        {
            SetWindowMonitor(monitor.get());
        }

        inline void Window::setSize(const int &width, const int &height)
        {
            SetWindowSize(width, height);
        }

        inline const int Window::getWidth()
        {
            return GetScreenWidth();
        }

        inline const int Window::getHeight()
        {
            return GetScreenWidth();
        }

        inline const API::Vector2D Window::position()
        {
            return static_cast<API::Vector2D>(GetWindowPosition());
        }

        inline void* Window::windowHandle()
        {
            return GetWindowHandle();
        }

        inline const std::string& Window::title() const
        {
            return m_title;
        }

        inline const std::string& Window::title()
        {
            return static_cast<const Window&>(*this).title();
        }

#ifdef PLATFORM_DESKTOP
        inline const bool Window::isHidden()
        {
            return IsWindowHidden();
        }

        inline const bool Window::isMaximized()
        {
            return IsWindowMaximized();
        }

        inline const bool Window::isMinimized()
        {
            return IsWindowMinimized();
        }

        inline const bool Window::isForcused()
        {
            return IsWindowFocused();
        }

        inline void Window::setState(const STATE_FLAG_TYPE& flag)
        {
            SetWindowState(flag);
        }

        inline void Window::toggleFullscreen()
        {
            return ToggleFullscreen();
        }

        inline void Window::setWindowState(const WindowState& state)
        {
            switch(state)
            {
                case WindowState::MAXIMIZE:
                    MaximizeWindow();
                    break;
                case WindowState::MINIMIZE:
                    MinimizeWindow();
                    break;
                case WindowState::RESTORE:
                    RestoreWindow();
                    break;
            }
        }

        inline void Window::setTitle(const std::string& title)
        {
            m_title = title;
            SetWindowTitle(m_title.c_str());
        }

        inline void Window::setPosition(const API::Vector2D& position)
        {
            SetWindowPosition(static_cast<int>(position.x()), static_cast<int>(position.y()));
        }

        inline void Window::setMinSize(const int& width, const int& height)
        {
            assert(isState(FLAG_WINDOW_RESIZABLE));
            SetWindowMinSize(width, height);
        }

        inline void Window::setOpacity(const float& opacity)
        {

        }
#endif
    } // namespace API

} // namespace SekaiEngine

#endif //! SEKAI_ENGINE_API_WINDOW_HPP