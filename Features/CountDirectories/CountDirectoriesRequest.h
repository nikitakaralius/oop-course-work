//
// Created by Nikita Karalyus on 16/12/2023.
//

#ifndef COUNTDIRECTORIESREQUEST_H
#define COUNTDIRECTORIESREQUEST_H

#include <sstream>
#include "../Common/FilesRequest.h"

class CountDirectoriesRequest final : public FilesRequest {
public:
    explicit CountDirectoriesRequest(
        const std::string directoryPath,
        const int maxDepthLevel)
        : FilesRequest(directoryPath, maxDepthLevel) { }

    std::string toString() override {
        std::stringstream ss;

        ss
        << "Подсчет количества директорий в "
        << directoryPath() << " "
        << maxDepthLevelDesription();

        return ss.str();
    }
};

#endif //COUNTDIRECTORIESREQUEST_H
