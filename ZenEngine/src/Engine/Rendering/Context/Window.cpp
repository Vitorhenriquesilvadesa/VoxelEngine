#include "Window.h"

namespace Zen
{
	Window::Window(Size size, const std::string& title)
	{
		mBackgroundColor = { 0.0f, 0.0f, 0.0f, 1.0f };
		glfwWindowHint(GLFW_MAXIMIZED, GLFW_TRUE);
		mId = glfwCreateWindow(size.width, size.height, title.c_str(), NULL, NULL);
		mSize = size;
		mTitle = title;
	}

	ZenWindowID* Window::GetNativeWindowID()
	{
		return mId;
	}

	void Window::SetSize(Size size)
	{
	}

	void Window::SetBackgroundColor(Color color)
	{
		mBackgroundColor = color;
		glClearColor(color.r, color.g, color.b, color.a);
	}

	void Window::Clear()
	{
		glClear(GL_COLOR_BUFFER_BIT);
	}

	void Window::SwapBuffers()
	{
		glfwSwapBuffers(mId);
	}

	void Window::PollEvents()
	{
		glfwPollEvents();
	}

}