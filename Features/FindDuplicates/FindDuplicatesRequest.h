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
        int maxDepthLevel,
        std::string target_file_path)
        : FilesRequest(directoryPath, maxDepthLevel),
          targetFilePath(std::move(target_file_path)) { }

    std::string toString() override {
        std::stringstream ss;

        ss
        << "Поиск дублирующихся файлов в "
        << getDirectoryPath() << " "
        << getMaxDepthLevelDesription();

        return ss.str();
    }

    std::string getTargetFilePath() const { return targetFilePath; }

private:
    std::string targetFilePath;
};

#endif //FINDDUPLICATESREQUEST_H
