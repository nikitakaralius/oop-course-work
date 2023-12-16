//
// Created by Nikita Karalyus on 16/12/2023.
//

#ifndef CONSOLELOGGERMIDDLEWARE_H
#define CONSOLELOGGERMIDDLEWARE_H

#include "../../Services/ConsoleLogger/ConsoleLogger.h"
#include "../LoggerMiddleware/LoggerMiddleware.h"

class ConsoleLoggerMiddleware final : public LoggerMiddleware {
public:
    explicit ConsoleLoggerMiddleware()
        : LoggerMiddleware(new ConsoleLogger()) { }
};

#endif //CONSOLELOGGERMIDDLEWARE_H
