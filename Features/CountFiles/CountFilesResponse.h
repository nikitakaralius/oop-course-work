//
// Created by Nikita Karalyus on 16/12/2023.
//

#ifndef COUNTFILESRESPONSE_H
#define COUNTFILESRESPONSE_H

#include <sstream>
#include "../../CQRS/Abstractions/IResponse.h"

class CountFilesResponse final : public IResponse {
public:
    explicit CountFilesResponse(const size_t fileCount)
        : _fileCount(fileCount) { }

    std::string toString() override {
        std::stringstream ss;
        ss << "Количество файлов = " << _fileCount;
        return ss.str();
    };

private:
    size_t _fileCount;
};

#endif //COUNTFILESRESPONSE_H
