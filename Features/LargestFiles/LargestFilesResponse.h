//
// Created by Nikita Karalyus on 16/12/2023.
//

#ifndef LARGESTFILESRESPONSE_H
#define LARGESTFILESRESPONSE_H

#include <sstream>
#include "../../CQRS/Abstractions/IResponse.h"
#include "../../FileSystem/Models/FileEntry/FileEntry.h"

class LargestFilesResponse final : public IResponse {
public:
    explicit LargestFilesResponse(const std::vector<FileEntry*>&largestFiles)
        : _largestFiles(largestFiles) {  }

    std::string toString() override {
        std::stringstream ss;

        for (const auto file : _largestFiles)
            ss << file->name() << " - " << file->size() << " байт" << "\n";

        return ss.str();
    }

private:
    std::vector<FileEntry*> _largestFiles;
};

#endif //LARGESTFILESRESPONSE_H
