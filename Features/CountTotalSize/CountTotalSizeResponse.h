//
// Created by Nikita Karalyus on 16/12/2023.
//

#ifndef COUNTTOTALSIZERESPONSE_H
#define COUNTTOTALSIZERESPONSE_H

#include <sstream>
#include "../../CQRS/Abstractions/IResponse.h"

class CountTotalSizeResponse final : public IResponse {
public:
    explicit CountTotalSizeResponse(long long total_size)
        : totalSize(total_size) { }

    std::string toString() override {
        std::stringstream ss;
        ss << "Суммарный размер файлов = " << totalSize << " байт";
        return ss.str();
    }

private:
    long long totalSize;
};

#endif //COUNTTOTALSIZERESPONSE_H
