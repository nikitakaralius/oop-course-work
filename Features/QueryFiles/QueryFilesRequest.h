//
// Created by Nikita Karalyus on 16/12/2023.
//

#ifndef QUERYFILESREQUEST_H
#define QUERYFILESREQUEST_H

#include <sstream>

#include "../../CQRS/Abstractions/IRequest.h"

class QueryFilesRequest : public IRequest {
public:
    explicit QueryFilesRequest(
        int maxDepthLevel,
        std::string directoryPath)
        : maxDepthLevel(maxDepthLevel),
          directoryPath(std::move(directoryPath)) {
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
    };

private:
    int maxDepthLevel;
    std::string directoryPath;
};

#endif //QUERYFILESREQUEST_H
