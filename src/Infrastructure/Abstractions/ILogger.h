//
// Created by Nikita Karalyus on 16/12/2023.
//

#ifndef ILOGGER_H
#define ILOGGER_H

#include <string>

class ILogger {
public:
    virtual ~ILogger() = default;

    virtual void log(std::string text) = 0;
};

#endif //ILOGGER_H
