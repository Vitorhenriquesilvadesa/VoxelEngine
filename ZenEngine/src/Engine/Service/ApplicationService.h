#pragma once

#include <string>
#include <unordered_map>
#include <any>
#include <stdexcept>

namespace Zen
{
    enum class ServiceType
    {
        Rendering, Physics, Event
    };

    struct ApplicationServiceState {
        bool IsInitialized = false;
        bool IsActive = false;
        std::string DebugInfo;
        std::unordered_map<std::string, std::any> StateData;

        template <typename T>
        void SetStateData(const std::string& key, const T& value) {
            StateData[key] = value;
        }

        template <typename T>
        T GetStateData(const std::string& key) const {
            auto it = StateData.find(key);
            if (it != StateData.end()) {
                return std::any_cast<T>(it->second);
            }
            throw std::runtime_error("Key not found in StateData: " + key);
        }
    };


	class ApplicationService
	{
	public:
		virtual void Init() = 0;
		virtual void Update() = 0;
		virtual void Shutdown() = 0;
		virtual ApplicationServiceState GetState() = 0;
		virtual void Suspend() = 0;
		virtual void Resume() = 0;
		virtual std::string GetName() = 0;
        virtual ServiceType GetType() = 0;
	};
}