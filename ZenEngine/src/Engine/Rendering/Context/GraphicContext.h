#pragma once

#include <Util/Types.h>
#include "Window.h"

namespace Zen
{
	class GraphicContext
	{
	public:
		void Init();
		void Clear();
		void SwapBuffers();
		void PollEvents();
		bool IsWindowClosed();

	private:
		Ref<Window> mWindow;
	};
}