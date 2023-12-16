//
// Created by Nikita Karalyus on 16/12/2023.
//

#ifndef NEWESTFILESRESPONSE_H
#define NEWESTFILESRESPONSE_H

#include "../../CQRS/Abstractions/IResponse.h"

class FileEntry;

class NewestFilesResponse final : IResponse {
public:
    NewestFilesResponse(std::vector<FileEntry*> newestFiles) : newestFiles(newestFiles) {  }

    std::string toString() override {

    };

private:
    std::vector<FileEntry*> newestFiles;
};

#endif //NEWESTFILESRESPONSE_H
