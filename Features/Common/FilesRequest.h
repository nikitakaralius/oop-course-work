//
// Created by Nikita Karalyus on 16/12/2023.
//

#ifndef FILESREQUEST_H
#define FILESREQUEST_H

#include <sstream>
#include "../../CQRS/Abstractions/IRequest.h"

class FilesRequest : public IRequest {
public:
    explicit FilesRequest(
        int maxDepthLevel,
        std::string directoryPath)
        : maxDepthLevel(maxDepthLevel),
          directoryPath(std::move(directoryPath)) { }

    std::string getDirectoryPath() const { return directoryPath; }

    int getMaxDepthLevel() const { return maxDepthLevel; }

    std::string getMaxDepthLevelDesription() const {
        if (maxDepthLevel == INT_MAX)
            return "c максимальной глубиной обхода";

        std::stringstream ss;
        ss << "с глубиной обхода = " << maxDepthLevel;

        return ss.str();
    }

private:
    int maxDepthLevel;
    std::string directoryPath;
};

#endif //FILESREQUEST_H
