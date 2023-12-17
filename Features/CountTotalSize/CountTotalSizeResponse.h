//
// Created by Nikita Karalyus on 16/12/2023.
//

#ifndef COUNTTOTALSIZERESPONSE_H
#define COUNTTOTALSIZERESPONSE_H

#include <sstream>
#include "../../CQRS/Abstractions/IResponse.h"

class CountTotalSizeResponse final : public IResponse {
public:
    explicit CountTotalSizeResponse(const long long totalSize)
        : _totalSize(totalSize) { }

    std::string toString() override {
        std::stringstream ss;
        ss << "Суммарный размер файлов = " << _totalSize << " байт";
        return ss.str();
    }

private:
    long long _totalSize;
};

#endif //COUNTTOTALSIZERESPONSE_H
