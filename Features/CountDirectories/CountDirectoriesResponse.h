//
// Created by Nikita Karalyus on 16/12/2023.
//

#ifndef COUNTDIRECTORIESRESPONSE_H
#define COUNTDIRECTORIESRESPONSE_H

#include <sstream>
#include "../../CQRS/Abstractions/IResponse.h"

class CountDirectoriesResponse final : public IResponse {
public:
    explicit CountDirectoriesResponse(const int directoryCount)
        : _directoryCount(directoryCount) { }

    std::string toString() override {
        std::stringstream ss;
        ss << "Количество папок = " << _directoryCount;
        return ss.str();
    }

private:
    int _directoryCount;
};

#endif //COUNTDIRECTORIESRESPONSE_H
