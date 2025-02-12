//
// Created by peter on 2/11/25.
//

#ifndef LOGGER_H
#define LOGGER_H

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wsign-conversion"
#include "spdlog/spdlog.h"
#pragma GCC diagnostic pop

std::shared_ptr<spdlog::logger> init_logger();


#endif //LOGGER_H

