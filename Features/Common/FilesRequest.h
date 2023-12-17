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
        const int maxDepthLevel)
        : _maxDepthLevel(maxDepthLevel),
          _directoryPath(std::move(directoryPath)) { }

    std::string directoryPath() const { return _directoryPath; }

    int maxDepthLevel() const { return _maxDepthLevel; }

    std::string maxDepthLevelDesription() const {
        if (_maxDepthLevel == INT_MAX)
            return "c максимальной глубиной обхода";

        std::stringstream ss;
        ss << "с глубиной обхода = " << _maxDepthLevel;

        return ss.str();
    }

private:
    int _maxDepthLevel;
    std::string _directoryPath;
};

#endif //FILESREQUEST_H
