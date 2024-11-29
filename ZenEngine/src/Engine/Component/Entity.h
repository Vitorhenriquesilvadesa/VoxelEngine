#pragma once

#include <cassert>
#include <Util/Types.h>
#include <unordered_map>
#include <typeindex>
#include <Component.h>

namespace Zen
{
    class Entity
    {
    public:
        template <typename T, typename... Args>
        Ref<Component> AddComponent(Args&&... args);

        template <typename T>
        Ref<T> GetComponent();

    private:
        std::unordered_map<std::type_index, Ref<Component>> mComponents;
    };

    template <typename T, typename... Args>
    Ref<Component> Entity::AddComponent(Args&&... args)
    {
        static_assert(std::is_base_of_v<Component, T>, "T must derive from Component");

        const std::type_index typeIndex(typeid(T));
        assert(!mComponents.contains(typeIndex)&& "Component already added!");

        Ref<T> component = std::make_shared<T>(std::forward<Args>(args)...);
        mComponents[typeIndex] = component;

        return component;
    }

    template <typename T>
    Ref<T> Entity::GetComponent()
    {
        static_assert(std::is_base_of_v<Component, T>, "T must derive from Component");

        const std::type_index typeIndex(typeid(T));

        if (const auto it = mComponents.find(typeIndex); it != mComponents.end())
        {
            return std::static_pointer_cast<T>(it->second);
        }

        return nullptr;
    }
}
