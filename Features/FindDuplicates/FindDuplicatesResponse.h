//
// Created by Nikita Karalyus on 16/12/2023.
//

#ifndef FINDDUPLICATESRESPONSE_H
#define FINDDUPLICATESRESPONSE_H

#include <sstream>
#include "../../CQRS/Abstractions/IResponse.h"
#include "../../FileSystem/Models/FileEntry/FileEntry.h"

class FindDuplicatesResponse final : public IResponse {
public:
    explicit FindDuplicatesResponse(
        const std::vector<FileEntry*>& duplicateFiles,
        const std::vector<FileEntry*>& allFiles)
    : _duplicateFiles(duplicateFiles),
      _allFiles(allFiles){  }

    ~FindDuplicatesResponse() override {
        for (const auto file : _allFiles)
            delete file;
    }

    std::string toString() override {
        std::stringstream ss;

        for (const auto file : _duplicateFiles)
            ss << file->getPath() << "\n";

        return ss.str();
    };

private:
    std::vector<FileEntry*> _duplicateFiles;
    std::vector<FileEntry*> _allFiles;
};

#endif //FINDDUPLICATESRESPONSE_H
