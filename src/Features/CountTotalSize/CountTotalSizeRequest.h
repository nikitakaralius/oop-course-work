//
// Created by Nikita Karalyus on 16/12/2023.
//

#ifndef COUNTTOTALSIZEREQUEST_H
#define COUNTTOTALSIZEREQUEST_H

#include <vector>
#include <sstream>

#include "../Common/FilesRequest.h"

class CountTotalSizeRequest final : public FilesRequest {
public:
    CountTotalSizeRequest(
        const std::string& directoryPath,
        const int maxDepthLevel)
        : FilesRequest(directoryPath, maxDepthLevel) { }

    std::string toString() override {
        std::stringstream ss;

        ss
        << "Подсчет суммарного размера файлов в "
        << directoryPath() << " "
        << maxDepthLevelDesription();

        return ss.str();
    }
};


#endif //COUNTTOTALSIZEREQUEST_H
