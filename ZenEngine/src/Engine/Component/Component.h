#pragma once

#include <Util/Types.h>
#include <unordered_map>
#include <typeindex>

namespace Zen
{
	class Entity;

	class Component
	{
	public:
		virtual void Start();
		virtual void Update();
		virtual void Dispose();

	protected:
		Ref<Entity> gameObject;
	};
}