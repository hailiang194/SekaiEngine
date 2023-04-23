#include "./Window.hpp"

SekaiEngine::API::Window::Window(const int &width, const int &height, const std::string &title)
    :m_title(title)
{
    InitWindow(width, height, m_title.c_str());
}

SekaiEngine::API::Window::~Window()
{
    CloseWindow();
}