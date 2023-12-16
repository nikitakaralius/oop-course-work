//
// Created by Nikita Karalyus on 16/12/2023.
//

#ifndef LARGESTFILESREQUEST_H
#define LARGESTFILESREQUEST_H
#include "../../CQRS/Abstractions/IRequest.h"

class LargestFilesRequest final : public IRequest {
public:
    std::string toString() override {

    }

private:
    std::string directoryPath;
    long long sizeThreshold;
};

#endif //LARGESTFILESREQUEST_H
