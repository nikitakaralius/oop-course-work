//
// Created by Nikita Karalyus on 16/12/2023.
//

#ifndef COUNTDIRECTORIESREQUEST_H
#define COUNTDIRECTORIESREQUEST_H

#include <sstream>
#include "../../CQRS/Abstractions/IRequest.h"

class CountDirectoriesRequest final : public IRequest {
public:
    CountDirectoriesRequest(std::string  directory_path, int depth_level)
        : directoryPath(std::move(directory_path)),
          depthLevel(depth_level) { }

    std::string toString() override {
        std::stringstream ss;

        ss
        << "Подсчет количества директорий в "
        << directoryPath;

        if (depthLevel == INT_MAX)
            ss << " c максимальной глубиной обхода";
        else
            ss << " с глубиной обхода = " << depthLevel;

        return ss.str();
    };

    std::string getDirectoryPath() const { return directoryPath; }
    int getDepthLevel() const { return depthLevel; }

private:
    std::string directoryPath;
    int depthLevel;
};

#endif //COUNTDIRECTORIESREQUEST_H
