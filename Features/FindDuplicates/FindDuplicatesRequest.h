//
// Created by Nikita Karalyus on 16/12/2023.
//

#ifndef FINDDUPLICATESREQUEST_H
#define FINDDUPLICATESREQUEST_H

#include <utility>
#include "../Common/FilesRequest.h"

class FindDuplicatesRequest final : public FilesRequest {
public:
    FindDuplicatesRequest(
        const std::string& directoryPath,
        const int maxDepthLevel,
        std::string targetFilePath)
        : FilesRequest(directoryPath, maxDepthLevel),
          _targetFilePath(std::move(targetFilePath)) { }

    std::string toString() override {
        std::stringstream ss;

        ss
        << "Поиск дублирующихся файлов в "
        << directoryPath() << " "
        << maxDepthLevelDesription();

        return ss.str();
    }

    std::string targetFilePath() const { return _targetFilePath; }

private:
    std::string _targetFilePath;
};

#endif //FINDDUPLICATESREQUEST_H
