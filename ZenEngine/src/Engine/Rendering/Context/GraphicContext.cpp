#include "GraphicContext.h"

#include <Debug/Logger.h>

namespace Zen
{
	void GraphicContext::Init()
	{
		if (!glfwInit())
		{
			DEBUG_ERROR("glfwInit", "Failed to initialize GLFW.");
		}

		mWindow = std::make_shared<Window>(Size{ 800, 600 }, "Zen Engine");
	}

	void GraphicContext::Clear()
	{
		mWindow->Clear();
	}

	void GraphicContext::SwapBuffers()
	{
		mWindow->SwapBuffers();
	}

	void GraphicContext::PollEvents()
	{
		mWindow->PollEvents();
	}
	bool GraphicContext::IsWindowClosed()
	{
		return glfwWindowShouldClose(mWindow->GetNativeWindowID());
	}
}