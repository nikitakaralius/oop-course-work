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
    explicit LargestFilesResponse(std::vector<FileEntry*> largestFiles) : largestFiles(largestFiles) {  }

    std::string toString() override {
        std::stringstream ss;

        for (const auto file : largestFiles)
            ss << file->name() << " - " << file->size() << " байт";

        return ss.str();
    }

private:
    std::vector<FileEntry*> largestFiles;
};

#endif //LARGESTFILESRESPONSE_H
