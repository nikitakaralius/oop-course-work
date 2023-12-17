//
// Created by Nikita Karalyus on 16/12/2023.
//

#ifndef FILELOGGERMIDDLEWARE_H
#define FILELOGGERMIDDLEWARE_H

#include "../../Services/FileLogger/FileLogger.h"
#include "../LoggerMiddleware/LoggerMiddleware.h"

class FileLoggerMiddleware final : public LoggerMiddleware {
public:
    explicit FileLoggerMiddleware(const std::string&filePath)
        : LoggerMiddleware(new FileLogger(filePath)) { }
};

#endif //FILELOGGERMIDDLEWARE_H
