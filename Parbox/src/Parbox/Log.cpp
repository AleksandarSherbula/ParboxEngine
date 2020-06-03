#include "pbxpch.h"
#include "Core.h"
#include "Log.h"

#include "spdlog/sinks/stdout_color_sinks.h"

namespace pbx
{
	std::shared_ptr<spdlog::logger> Log::logger;

	void Log::Init()
	{
		spdlog::set_pattern("%^[%T] [%l]: %v%$");
		logger = spdlog::stdout_color_mt("PARBOX");
		logger->set_level(spdlog::level::trace);
	}	
}