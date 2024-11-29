#include "Window.h"

namespace Zen
{
    Window::Window(const Size size, const std::string& title)
    {
        mBackgroundColor = {0.0f, 0.0f, 0.0f, 1.0f};
        glfwWindowHint(GLFW_MAXIMIZED, GLFW_TRUE);
        mId = glfwCreateWindow(size.width, size.height, title.c_str(), nullptr, nullptr);
        mSize = size;
        mTitle = title;
    }

    ZenWindowID* Window::GetNativeWindowID() const
    {
        return mId;
    }

    void Window::SetSize(const Size size)
    {
        glViewport(0, 0, size.width, size.height);
        mSize = size;
    }

    void Window::SetBackgroundColor(Color color)
    {
        mBackgroundColor = color;
        glClearColor(color.r, color.g, color.b, color.a);
    }

    void Window::Clear() const
    {
        glClear(GL_COLOR_BUFFER_BIT);
    }

    void Window::SwapBuffers() const
    {
        glfwSwapBuffers(mId);
    }

    void Window::PollEvents() const
    {
        glfwPollEvents();
    }
}
