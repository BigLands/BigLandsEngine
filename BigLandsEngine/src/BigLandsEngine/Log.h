#pragma once

#include <memory>

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"

namespace BigLandsEngine {
	class BIGLANDSENGINE_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger;  }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};
}

// Core Log macros
#define BE_CORE_ERROR(...)       ::BigLandsEngine::Log::GetCoreLogger()->error(__VA_ARGS__)
#define BE_CORE_WARN(...)        ::BigLandsEngine::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define BE_CORE_INFO(...)        ::BigLandsEngine::Log::GetCoreLogger()->info(__VA_ARGS__)
#define BE_CORE_TRACE(...)       ::BigLandsEngine::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define BE_CORE_FATAL(...)       ::BigLandsEngine::Log::GetCoreLogger()->fatal(__VA_ARGS__)

// Client Log macros

#define BE_ERROR(...)       ::BigLandsEngine::Log::GetClientLogger()->error(__VA_ARGS__)
#define BE_WARN(...)        ::BigLandsEngine::Log::GetClientLogger()->warn(__VA_ARGS__)
#define BE_INFO(...)        ::BigLandsEngine::Log::GetClientLogger()->info(__VA_ARGS__)
#define BE_TRACE(...)       ::BigLandsEngine::Log::GetClientLogger()->trace(__VA_ARGS__)
#define BE_FATAL(...)       ::BigLandsEngine::Log::GetClientLogger()->fatal(__VA_ARGS__)