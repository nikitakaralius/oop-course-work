//
// Created by Nikita Karalyus on 16/12/2023.
//

#include "ConsoleLogger.h"

#include <iostream>

constexpr const char* ANSI_COLOR_RED = "\x1b[31m";
constexpr const char* ANSI_COLOR_GREEN = "\x1b[32m";
constexpr const char* ANSI_COLOR_RESET = "\x1b[0m";

void ConsoleLogger::log(const std::string text) {
    std::cout
    << ANSI_COLOR_GREEN
    << "[LOG]\t"
    << text
    << ANSI_COLOR_RESET
    << std::endl;
}
