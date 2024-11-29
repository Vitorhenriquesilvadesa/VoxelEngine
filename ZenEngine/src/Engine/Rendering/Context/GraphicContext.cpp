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

        mWindow = std::make_shared<Window>(Size{800, 600}, "Zen Engine");
    }

    void GraphicContext::Clear() const
    {
        mWindow->Clear();
    }

    void GraphicContext::SwapBuffers() const
    {
        mWindow->SwapBuffers();
    }

    void GraphicContext::PollEvents() const
    {
        mWindow->PollEvents();
    }

    bool GraphicContext::IsWindowClosed() const
    {
        return glfwWindowShouldClose(mWindow->GetNativeWindowID());
    }
}
