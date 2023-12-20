//
// Created by Nikita Karalyus on 16/12/2023.
//

#ifndef CONSOLELOGGER_H
#define CONSOLELOGGER_H

#include "../../Abstractions/ILogger.h"


class ConsoleLogger final : public ILogger {
public:
    void log(std::string text) override;
};



#endif //CONSOLELOGGER_H
