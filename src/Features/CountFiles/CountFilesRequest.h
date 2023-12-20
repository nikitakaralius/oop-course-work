//
// Created by Nikita Karalyus on 16/12/2023.
//

#ifndef COUNTFILESREQUEST_H
#define COUNTFILESREQUEST_H

#include <sstream>
#include "../Common/FilesRequest.h"

class CountFilesRequest final : public FilesRequest {
public:
    explicit CountFilesRequest(
        const std::string& directoryPath,
        const int maxDepthLevel)
        : FilesRequest(directoryPath, maxDepthLevel) { }

    std::string toString() override {
        std::stringstream ss;

        ss
        << "Подсчет количества файлов в "
        << directoryPath() << " "
        << maxDepthLevelDesription();

        return ss.str();
    }
};

#endif //COUNTFILESREQUEST_H
