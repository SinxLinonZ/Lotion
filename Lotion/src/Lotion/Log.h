#pragma once

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"

namespace Lotion
{
	class LOTION_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
		
	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};

}

// Core log macros
#define LT_CORE_TRACE(...)      :: Lotion::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define LT_CORE_INFO(...)       :: Lotion::Log::GetCoreLogger()->info(__VA_ARGS__)
#define LT_CORE_WARN(...)       :: Lotion::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define LT_CORE_ERROR(...)      :: Lotion::Log::GetCoreLogger()->error(__VA_ARGS__)
#define LT_CORE_CRITICAL(...)   :: Lotion::Log::GetCoreLogger()->critical(__VA_ARGS__)

// Client log macros
#define LT_TRACE(...)           :: Lotion::Log::GetClientLogger()->trace(__VA_ARGS__)
#define LT_INFO(...)            :: Lotion::Log::GetClientLogger()->info(__VA_ARGS__)
#define LT_WARN(...)            :: Lotion::Log::GetClientLogger()->warn(__VA_ARGS__)
#define LT_ERROR(...)           :: Lotion::Log::GetClientLogger()->error(__VA_ARGS__)
#define LT_CRITICAL(...)        :: Lotion::Log::GetClientLogger()->critical(__VA_ARGS__)

