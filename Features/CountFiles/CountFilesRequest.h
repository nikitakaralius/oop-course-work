//
// Created by Nikita Karalyus on 16/12/2023.
//

#ifndef COUNTFILESREQUEST_H
#define COUNTFILESREQUEST_H

#include <sstream>
#include "../Common/FilesRequest.h"

class CountFilesRequest final : public FilesRequest {
public:
    CountFilesRequest(const std::string& directoryPath, int maxDepthLevel)
        : FilesRequest(directoryPath, maxDepthLevel) { }

    std::string toString() override {
        std::stringstream ss;

        ss
        << "Подсчет количества файлов в "
        << getDirectoryPath() << " "
        << getMaxDepthLevelDesription();

        return ss.str();
    }
};

#endif //COUNTFILESREQUEST_H
