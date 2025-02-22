//
// Created by peter on 2/11/25.
//

#include "../include/Logger.h"

#include "spdlog/sinks/basic_file_sink.h"
#include "spdlog/sinks/stdout_color_sinks-inl.h"



void test_logger() {
    spdlog::trace("TRACE");
    spdlog::debug("DEBUG");
    spdlog::info("INFO");
    spdlog::warn("WARN");
    spdlog::error("ERROR");
    spdlog::critical("CRITICAL");
}


std::shared_ptr<spdlog::logger> init_logger() {
    auto consoleSink = std::make_shared<spdlog::sinks::stdout_color_sink_mt>();

    auto logFileSink = std::make_shared<spdlog::sinks::basic_file_sink_mt>(std::string(LOG_DIRECTORY) + "/message.log", true);
    logFileSink->set_level(spdlog::level::trace);

    std::shared_ptr<spdlog::logger> l = std::make_shared<spdlog::logger>("Kangaroo_logger");
    l->flush_on(spdlog::level::trace);
    l->sinks().push_back(consoleSink);
    l->sinks().push_back(logFileSink);

    l->set_level(spdlog::level::trace);
    l->set_pattern("%^[%Y-%m-%d %T] %n.%l: %v%$");

    spdlog::set_default_logger(l);

    return l;
}
