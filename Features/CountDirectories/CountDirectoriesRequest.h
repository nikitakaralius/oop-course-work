//
// Created by Nikita Karalyus on 16/12/2023.
//

#ifndef COUNTDIRECTORIESREQUEST_H
#define COUNTDIRECTORIESREQUEST_H

#include <sstream>
#include "../../CQRS/Abstractions/IRequest.h"

class CountDirectoriesRequest final : IRequest {
public:
    CountDirectoriesRequest(const std::string& directory_path, int depth_level)
        : directoryPath(directory_path),
          depthLevel(depth_level) { }

    std::string toString() override {
        std::stringstream ss;

        ss
        << "Подсчет количества директорий в "
        << directoryPath
        << " c глубиной обхода "
        << depthLevel;

        return ss.str();
    };

    std::string getDirectoryPath() const { return directoryPath; }
    int getDepthLevel() const { return depthLevel; }

private:
    std::string directoryPath;
    int depthLevel;
};

#endif //COUNTDIRECTORIESREQUEST_H
