#pragma once

#include <Util/Types.h>

namespace Zen
{
    class Entity;

    class Component
    {
    public:
        virtual ~Component() = default;
        virtual void Start() = 0;
        virtual void Update() = 0;
        virtual void Dispose() = 0;

    protected:
        Ref<Entity> gameObject;
    };
}
