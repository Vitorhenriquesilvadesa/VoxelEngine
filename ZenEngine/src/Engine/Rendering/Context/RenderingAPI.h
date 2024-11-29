#pragma once

#include <Engine/Service/ApplicationService.h>
#include "GraphicContext.h"

namespace Zen
{
	class RenderingAPI : public ApplicationService
	{
		
	public:
		virtual ~RenderingAPI() = default;

		RenderingAPI();

		bool IsWindowCloseRequested() const;
		void Init() override;
		void Update() override;
		void Shutdown() override;
		ApplicationServiceState GetState() override;
		void Suspend() override;
		void Resume() override;
		std::string GetName() override;
		ServiceType GetType() override;

	private:
		GraphicContext mContext;
	};
}