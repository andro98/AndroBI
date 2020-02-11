#pragma once

#include"Core.h"
#include"spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"

namespace AndroBI
{
	class ANDROBI_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() {
			return s_CoreLogger;
		}
		
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() {
			return s_ClientLogger;
		}

	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};
}

// Core log macros
#define ABI_CORE_TRACE(...)      ::AndroBI::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define ABI_CORE_INFO(...)       ::AndroBI::Log::GetCoreLogger()->info(__VA_ARGS__)
#define ABI_CORE_WARN(...)       ::AndroBI::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define ABI_CORE_ERROR(...)      ::AndroBI::Log::GetCoreLogger()->error(__VA_ARGS__)
#define ABI_CORE_FATAL(...)      ::AndroBI::Log::GetCoreLogger()->fatal(__VA_ARGS__)

// Client log macros
#define ABI_TRACE(...)           ::AndroBI::Log::GetClientLogger()->trace(__VA_ARGS__)
#define ABI_INFO(...)            ::AndroBI::Log::GetClientLogger()->info(__VA_ARGS__)
#define ABI_WARN(...)            ::AndroBI::Log::GetClientLogger()->warn(__VA_ARGS__)
#define ABI_ERROR(...)           ::AndroBI::Log::GetClientLogger()->error(__VA_ARGS__)
#define ABI_FATAL(...)           ::AndroBI::Log::GetClientLogger()->fatal(__VA_ARGS__)