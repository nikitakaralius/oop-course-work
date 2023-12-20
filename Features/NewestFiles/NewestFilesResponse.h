//
// Created by Nikita Karalyus on 16/12/2023.
//

#ifndef NEWESTFILESRESPONSE_H
#define NEWESTFILESRESPONSE_H

#include <sstream>

#include "../../CQRS/Abstractions/IResponse.h"
#include "../../FileSystem/Models/FileEntry/FileEntry.h"
#include <vector>


class FileEntry;

class NewestFilesResponse final : public IResponse {
public:
    explicit NewestFilesResponse(
        const std::vector<FileEntry*> newestFiles,
        const std::vector<FileEntry*> allFiles)
        : _newestFiles(newestFiles),
          _allFiles(allFiles) {  }

    ~NewestFilesResponse() override {
        for (const auto file : _allFiles)
            delete file;
    }

    std::string toString() override {
        std::stringstream ss;

        for (const auto file : _newestFiles) {
            time_t createdAt = file->updatedAt();
            ss << file->name() << " - " << std::ctime(&createdAt);
        }

        return ss.str();
    };

private:
    std::vector<FileEntry*> _newestFiles;
    std::vector<FileEntry*> _allFiles;
};

#endif //NEWESTFILESRESPONSE_H
