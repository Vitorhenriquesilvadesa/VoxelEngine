#pragma once

#include "Texture.h"
#include "Shader.h"

namespace Zen
{
	struct Material
	{
		Shader shader;
		Texture albedo;
	};
}