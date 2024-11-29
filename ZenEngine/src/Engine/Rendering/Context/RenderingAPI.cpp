#include "RenderingAPI.h"

#include <Debug/Logger.h>
#include <Engine.h>


namespace Zen
{
	RenderingAPI::RenderingAPI()
	{
		mContext = GraphicContext();
	}

	bool RenderingAPI::IsWindowCloseRequested() const
	{
		return mContext.IsWindowClosed();
	}

	void RenderingAPI::Init()
	{
		mContext.Init();
		Engine::RegisterFlag(ApplicationFlag::WindowClosed, [this] { return IsWindowCloseRequested(); });
	}

	void RenderingAPI::Update() 
	{
		mContext.SwapBuffers();
		mContext.PollEvents();
	}

	void RenderingAPI::Shutdown()
	{
	}

	ApplicationServiceState RenderingAPI::GetState()
	{
		return ApplicationServiceState{
			.IsActive = true,
			.DebugInfo = "Rendering State",
			.StateData = {}
		};
	}
	void RenderingAPI::Suspend()
	{
	}

	void RenderingAPI::Resume()
	{
	}

	std::string RenderingAPI::GetName()
	{
		return "RenderingAPI";
	}

	ServiceType RenderingAPI::GetType()
	{
		return ServiceType::Rendering;
	}
}