#include "./Window.hpp"

SekaiEngine::API::Window::Window(const int &width, const int &height, const std::string &title)
    :m_title(title)
{
#ifdef RAYLIB_API
    InitWindow(width, height, m_title.c_str());
#else
#endif
}

SekaiEngine::API::Window::~Window()
{
#ifdef RAYLIB_API
    CloseWindow();
#else
#endif
}