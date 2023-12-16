//
// Created by Nikita Karalyus on 16/12/2023.
//

#ifndef COUNTFILESREQUEST_H
#define COUNTFILESREQUEST_H

#include <sstream>
#include "../../CQRS/Abstractions/IRequest.h"

class CountFilesRequest final : public IRequest {
public:
    CountFilesRequest(std::string directoryPath, int maxDepthLevel)
        : directoryPath(std::move(directoryPath)),
          maxDepthLevel(maxDepthLevel) {
    }

    std::string getDirectoryPath() const { return directoryPath; }

    int getMaxDepthLevel() const { return maxDepthLevel; }

    std::string toString() override {
        std::stringstream ss;

        ss
        << "Подсчет количества файлов в "
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

#endif //COUNTFILESREQUEST_H
