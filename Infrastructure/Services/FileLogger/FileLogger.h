//
// Created by Nikita Karalyus on 16/12/2023.
//

#ifndef FILELOGGER_H
#define FILELOGGER_H

#include <utility>

#include "../../Abstractions/ILogger.h"


class FileLogger final : public ILogger {
public:
    explicit FileLogger(std::string  filePath)
    : filePath(std::move(filePath)) {}

    void log(std::string text) override;

private:
    std::string filePath;
};



#endif //FILELOGGER_H
