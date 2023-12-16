//
// Created by Nikita Karalyus on 16/12/2023.
//

#ifndef QUERYFILESRESPONSE_H
#define QUERYFILESRESPONSE_H


#include <sstream>
#include "../../CQRS/Abstractions/IResponse.h"
#include "../../FileSystem/Models/FileEntry/FileEntry.h"

class QueryFilesResponse final : public IResponse {
public:
    QueryFilesResponse(std::vector<FileEntry*> files) : files(files) { }

    ~QueryFilesResponse() override {
        for (const auto file : files)
            delete file;
    }

    std::string toString() override {
        std::stringstream ss;
        for (const auto file : files) {
            ss << file->name() << "\n";
        }
        return ss.str();
    };

private:
    std::vector<FileEntry*> files;
};

#endif //QUERYFILESRESPONSE_H
