#include "Engine.h"
#include <Debug/Logger.h>
#include <Rendering/Context/RenderingAPI.h>

namespace Zen
{
	Ref<Engine> Engine::sInstance;

	void Engine::Init()
	{
		sInstance = std::make_shared<Engine>();
		sInstance->mServices = {};
		sInstance->mFlags = {};
		sInstance->mIsRunning = true;

		if (!sInstance)
		{
			sInstance = std::make_shared<Engine>();
		}

		DEBUG_MESSAGE("Engine::Init", "Initializing engine.");

		sInstance->RegisterServices();

		for (const auto& service : sInstance->mServices)
		{
			service.second->Init();
		}
	}

	void Engine::Update()
	{
		for (const auto& service : sInstance->mServices)
		{
			service.second->Update();
		}
	}

	void Engine::Shutdown()
	{
		DEBUG_MESSAGE("Engine::Shutdown", "Shutdowning engine.");
	}

	void Engine::RegisterFlag(ApplicationFlag flag, FlagFunction function)
	{
		sInstance->mFlags.insert({flag, function});
	}

	bool Engine::GetFlag(ApplicationFlag flag)
	{
		return sInstance->mFlags.at(flag)();
	}

	bool Engine::IsRunning() const
	{
		return mIsRunning;
	}

	void Engine::RegisterServices()
	{
		RegisterService<RenderingAPI>();
	}

	void Engine::UpdateServices()
	{
	}
}