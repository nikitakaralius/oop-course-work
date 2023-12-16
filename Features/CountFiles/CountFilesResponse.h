//
// Created by Nikita Karalyus on 16/12/2023.
//

#ifndef COUNTFILESRESPONSE_H
#define COUNTFILESRESPONSE_H

#include <sstream>
#include "../../CQRS/Abstractions/IResponse.h"

class CountFilesResponse : public IResponse {
public:
    explicit CountFilesResponse(int fileCount)
        : fileCount(fileCount) { }

    std::string toString() override {
        std::stringstream ss;
        ss << "Количество файлов = " << fileCount;
        return ss.str();
    };

private:
    int fileCount;
};

#endif //COUNTFILESRESPONSE_H
