//
// Created by Nikita Karalyus on 16/12/2023.
//

#ifndef NEWESTFILESRESPONSE_H
#define NEWESTFILESRESPONSE_H

#include <sstream>

#include "../../CQRS/Abstractions/IResponse.h"
#include "../../FileSystem/Models/FileEntry/FileEntry.h"

class FileEntry;

class NewestFilesResponse final : public IResponse {
public:
    explicit NewestFilesResponse(std::vector<FileEntry*> newestFiles) : newestFiles(newestFiles) {  }

    std::string toString() override {
        std::stringstream ss;

        for (const auto file : newestFiles) {
            time_t createdAt = file->createdAt();
            ss << file->name() << " - " << std::ctime(&createdAt) << "\n";
        }

        return ss.str();
    };

private:
    std::vector<FileEntry*> newestFiles;
};

#endif //NEWESTFILESRESPONSE_H
