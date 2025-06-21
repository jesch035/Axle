#pragma once
#include "Core.h"
#include <spdlog/spdlog.h>
#include <spdlog/fmt/ostr.h>


namespace Axle
{
	class Log
	{
	public:
		AXLE_API static void Init();

		AXLE_API static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		AXLE_API static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }

	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};
}

// Core logging macros
#define AX_CORE_TRACE(...)	::Axle::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define AX_CORE_INFO(...)	::Axle::Log::GetCoreLogger()->info(__VA_ARGS__)
#define AX_CORE_WARN(...)	::Axle::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define AX_CORE_ERROR(...)	::Axle::Log::GetCoreLogger()->error(__VA_ARGS__)
#define AX_CORE_FATAL(...)	::Axle::Log::GetCoreLogger()->fatal(__VA_ARGS__)

// Client logging macros
#define AX_TRACE(...)		::Axle::Log::GetClientLogger()->trace(__VA_ARGS__)
#define AX_INFO(...)		::Axle::Log::GetClientLogger()->info(__VA_ARGS__)
#define AX_WARN(...)		::Axle::Log::GetClientLogger()->warn(__VA_ARGS__)
#define AX_ERROR(...)		::Axle::Log::GetClientLogger()->error(__VA_ARGS__)
#define AX_FATAL(...)		::Axle::Log::GetClientLogger()->fatal(__VA_ARGS__)