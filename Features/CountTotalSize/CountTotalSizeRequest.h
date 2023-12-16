//
// Created by Nikita Karalyus on 16/12/2023.
//

#ifndef COUNTTOTALSIZEREQUEST_H
#define COUNTTOTALSIZEREQUEST_H

#include <sstream>
#include "../../CQRS/Abstractions/IRequest.h"

class CountTotalSizeRequest : public IRequest {
public:
    CountTotalSizeRequest(std::string directoryPath, int maxDepthLevel)
        : directoryPath(std::move(directoryPath)),
          maxDepthLevel(maxDepthLevel) {
    }

    std::string getDirectoryPath() const { return directoryPath; }

    int getMaxDepthLevel() const { return maxDepthLevel; }

    std::string toString() override {
        std::stringstream ss;

        ss
        << "Подсчет суммарного размера файлов в "
        << directoryPath;

        if (maxDepthLevel == INT_MAX)
            ss << " c максимальной глубиной обхода";
        else
            ss << " с глубиной обхода = " << maxDepthLevel;

        return ss.str();
    }

private:
    std::string directoryPath;
    int maxDepthLevel;
};


#endif //COUNTTOTALSIZEREQUEST_H
