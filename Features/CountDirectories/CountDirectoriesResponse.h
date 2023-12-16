//
// Created by Nikita Karalyus on 16/12/2023.
//

#ifndef COUNTDIRECTORIESRESPONSE_H
#define COUNTDIRECTORIESRESPONSE_H

#include <sstream>
#include "../../CQRS/Abstractions/IResponse.h"

class CountDirectoriesResponse final : public IResponse {
public:
    explicit CountDirectoriesResponse(int directoryCount)
        : directoryCount(directoryCount) { }

    std::string toString() override {
        std::stringstream ss;
        ss << "Количество папок = " << directoryCount;
        return ss.str();
    };

private:
    int directoryCount;
};

#endif //COUNTDIRECTORIESRESPONSE_H
