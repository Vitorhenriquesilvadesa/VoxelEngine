#pragma once

#include "Service/ApplicationService.h"
#include <Util/Types.h>
#include <Debug/Logger.h>
#include <EngineFlags.h>

namespace Zen
{
	class Engine
	{
	public:
		Engine() = default;
		static void Init();
		static void Update();
		static void Shutdown();

		static void RegisterFlag(ApplicationFlag flag, FlagFunction function);
		static bool GetFlag(ApplicationFlag flag);

		bool IsRunning() const;

	private:
		template<typename T>
		void RegisterService();
		void RegisterServices();
		void UpdateServices();

		std::unordered_map<ServiceType, Ref<ApplicationService>> mServices;
		std::unordered_map<ApplicationFlag, FlagFunction> mFlags;
		bool mIsRunning;

		static Ref<Engine> sInstance;
	};

	template<typename T>
	inline void Engine::RegisterService()
	{
		Ref<ApplicationService> service = std::make_shared<T>();
		DEBUG_MESSAGE("Engine::RegisterService", std::format("Registering {}.", service->GetName()));
		mServices.insert({service->GetType(), service});
	}
}