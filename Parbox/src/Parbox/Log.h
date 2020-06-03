#pragma once

#include "spdlog/spdlog.h"

namespace pbx
{
	class PARBOX_DLL Log
	{
	private:
		static std::shared_ptr<spdlog::logger> logger;
	public:
		static void Init();

		static std::shared_ptr<spdlog::logger> GetLogger() { return logger; }
	};
}


#define PBX_LOG_TRACE(...)    ::pbx::Log::GetLogger()->trace(__VA_ARGS__)
#define PBX_LOG_INFO(...)     ::pbx::Log::GetLogger()->info(__VA_ARGS__)
#define PBX_LOG_WARN(...)     ::pbx::Log::GetLogger()->warn(__VA_ARGS__)
#define PBX_LOG_ERROR(...)    ::pbx::Log::GetLogger()->error(__VA_ARGS__)
#define PBX_LOG_CRITICAL(...) ::pbx::Log::GetLogger()->critical(__VA_ARGS__)

#ifdef PBX_DEBUG
#define PBX_ASSERT(x, ...) if (!x) {PBX_LOG_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak();}
#else
#define PBX_ASSERT(x, ...)
#endif
