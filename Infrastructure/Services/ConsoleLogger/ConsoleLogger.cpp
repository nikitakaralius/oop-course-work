//
// Created by Nikita Karalyus on 16/12/2023.
//

#include "ConsoleLogger.h"

#include <iostream>

void ConsoleLogger::Log(std::string text) {
    std::cout << "[LOG]\t" << text << std::endl;
}
