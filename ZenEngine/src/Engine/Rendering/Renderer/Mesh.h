#pragma once

#include <glm/glm.hpp>
#include <vector>

namespace Zen
{
	struct Mesh
	{
		std::vector<glm::vec3> vertices;
		std::vector<unsigned int> indices;
		std::vector<float> uv;
	};
}