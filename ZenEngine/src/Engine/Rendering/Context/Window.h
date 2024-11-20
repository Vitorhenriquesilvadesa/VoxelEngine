#pragma once

#include <Util/Metrics.h>
#include <GLFW/glfw3.h>
#include <string>

namespace Zen
{
	typedef GLFWwindow ZenWindowID;

	class Window
	{
	public:
		Window(Size size, const std::string& title);

		Size GetSize() const { return mSize; }
		Color GetBackgroundColor() const { return mBackgroundColor; }
		ZenWindowID* GetNativeWindowID();

		void SetSize(Size size);
		void SetBackgroundColor(Color color);

		void Clear();
		void SwapBuffers();
		void PollEvents();

	private:
		Size mSize;
		std::string mTitle;
		ZenWindowID* mId;
		Color mBackgroundColor;
	};
}