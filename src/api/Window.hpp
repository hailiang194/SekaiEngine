#ifndef SEKAI_ENGINE_API_WINDOW_HPP
#define SEKAI_ENGINE_API_WINDOW_HPP

#include "./Monitor.hpp"
#include "api/Vector.hpp"
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
        private:
            std::string m_title;
        };

        inline const bool Window::isReady()
        {
#ifdef RAYLIB_API
            return IsWindowReady();
#else
#endif
        }

        inline const bool Window::shouldClose()
        {
#ifdef RAYLIB_API
            return WindowShouldClose();
#else
#endif
        }

        inline const bool Window::isFullScreen()
        {
#ifdef RAYLIB_API
            return IsWindowFullscreen();
#else
#endif
        }

        inline const bool Window::isResized()
        {
#ifdef RAYLIB_API
            return IsWindowResized();
#else
#endif
        }

        inline const bool Window::isState(const STATE_FLAG_TYPE& flag)
        {
#ifdef RAYLIB_API
            return IsWindowState(flag);
#else
#endif
        }

        inline void Window::clearState(const STATE_FLAG_TYPE& flag)
        {
#ifdef RAYLIB_API
            ClearWindowState(flag);
#else
#endif
        }

        inline void Window::setMonitor(const Monitor &monitor)
        {
#ifdef RAYLIB_API
            SetWindowMonitor(monitor.get());
#else
#endif
        }

        inline void Window::setSize(const int &width, const int &height)
        {
#ifdef RAYLIB_API
            SetWindowSize(width, height);
#else
#endif
        }

        inline const int Window::getWidth()
        {
#ifdef RAYLIB_API
            return GetScreenWidth();
#else
#endif
        }

        inline const int Window::getHeight()
        {
#ifdef RAYLIB_API
            return GetScreenWidth();
#else
#endif
        }

        inline const API::Vector2D Window::position()
        {
#ifdef RAYLIB_API
            return static_cast<API::Vector2D>(GetWindowPosition());
#else
#endif
        }

        inline void* Window::windowHandle()
        {
#ifdef RAYLIB_API
            return GetWindowHandle();
#else
#endif
        }

        inline const std::string& Window::title() const
        {
            return m_title;
        }

        inline const std::string& Window::title()
        {
            return static_cast<const Window&>(*this).title();
        }

        inline const bool Window::isHidden()
        {
#ifdef RAYLIB_API
            return IsWindowHidden();
#else
#endif
        }

        inline const bool Window::isMaximized()
        {
#ifdef RAYLIB_API
            return IsWindowMaximized();
#else
#endif
        }

        inline const bool Window::isMinimized()
        {
#ifdef RAYLIB_API
            return IsWindowMinimized();
#else
#endif
        }

        inline const bool Window::isForcused()
        {
#ifdef RAYLIB_API
            return IsWindowFocused();
#else
#endif
        }

        inline void Window::setState(const STATE_FLAG_TYPE& flag)
        {
#ifdef RAYLIB_API
            SetWindowState(flag);
#else
#endif
        }

        inline void Window::toggleFullscreen()
        {
#ifdef RAYLIB_API
            ToggleFullscreen();
#else
#endif
        }

        inline void Window::setWindowState(const WindowState& state)
        {
            switch(state)
            {
                case WindowState::MAXIMIZE:
#ifdef RAYLIB_API
                    MaximizeWindow();
#else
#endif
                    break;
                case WindowState::MINIMIZE:
#ifdef RAYLIB_API
                    MinimizeWindow();
#else
#endif
                    break;
                case WindowState::RESTORE:
#ifdef RAYLIB_API
                    RestoreWindow();
#else
#endif
                    break;
            }
        }

        inline void Window::setTitle(const std::string& title)
        {
            m_title = title;
#ifdef RAYLIB_API
            SetWindowTitle(m_title.c_str());
#else
#endif
        }

        inline void Window::setPosition(const API::Vector2D& position)
        {
#ifdef RAYLIB_API
            SetWindowPosition(static_cast<int>(position.x()), static_cast<int>(position.y()));
#else
#endif
        }

        inline void Window::setMinSize(const int& width, const int& height)
        {
#ifdef RAYLIB_API
            assert(isState(FLAG_WINDOW_RESIZABLE));
            SetWindowMinSize(width, height);
#else
#endif
        }

        inline void Window::setOpacity(const float& opacity)
        {
#ifdef RAYLIB_API
            assert(1 == 1 && "Not supported yet");
#else
#endif
        }
    } // namespace API

} // namespace SekaiEngine

#endif //! SEKAI_ENGINE_API_WINDOW_HPP