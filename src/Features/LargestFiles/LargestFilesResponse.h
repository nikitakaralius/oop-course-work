//
// Created by Nikita Karalyus on 16/12/2023.
//

#ifndef LARGESTFILESRESPONSE_H
#define LARGESTFILESRESPONSE_H

#include <sstream>
#include <vector>
#include "../../CQRS/Abstractions/IResponse.h"
#include "../../FileSystem/Models/FileEntry/FileEntry.h"

class LargestFilesResponse final : public IResponse {
public:
    explicit LargestFilesResponse(
        const std::vector<FileEntry*> largestFiles,
        const std::vector<FileEntry*> allFiles)
        : _largestFiles(largestFiles),
          _allFiles(allFiles){  }

    ~LargestFilesResponse() override {
        for (const auto file : _allFiles)
            delete file;
    }

    std::string toString() override {
        std::stringstream ss;

        for (const auto file : _largestFiles)
            ss << file->name() << " - " << file->size() << " байт" << "\n";

        return ss.str();
    }

private:
    std::vector<FileEntry*> _largestFiles;
    std::vector<FileEntry*> _allFiles;
};

#endif //LARGESTFILESRESPONSE_H
