#pragma once

#include <functional>

namespace Zen
{
	enum class ApplicationFlag
	{
		WindowClosed
	};

	typedef std::function<bool()> FlagFunction;
}