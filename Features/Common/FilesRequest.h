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
        std::string directoryPath,
        int maxDepthLevel)
        : directoryPath(std::move(directoryPath)),
          maxDepthLevel(maxDepthLevel) { }

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
