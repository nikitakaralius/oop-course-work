//
// Created by Nikita Karalyus on 16/12/2023.
//

#ifndef COUNTDIRECTORIESRESPONSE_H
#define COUNTDIRECTORIESRESPONSE_H

#include <vector>
#include <sstream>

#include "../../CQRS/Abstractions/IResponse.h"

class CountDirectoriesResponse final : public IResponse {
public:
    explicit CountDirectoriesResponse(const size_t directoryCount)
        : _directoryCount(directoryCount) { }

    std::string toString() override {
        std::stringstream ss;
        ss << "Количество папок = " << _directoryCount;
        return ss.str();
    }

private:
    size_t _directoryCount;
};

#endif //COUNTDIRECTORIESRESPONSE_H
