#pragma once

#include <Util/Types.h>
#include "Window.h"

namespace Zen
{
	class GraphicContext
	{
	public:
		void Init();
		void Clear() const;
		void SwapBuffers() const;
		void PollEvents() const;
		bool IsWindowClosed() const;

	private:
		Ref<Window> mWindow;
	};
}