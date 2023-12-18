//
// Created by Nikita Karalyus on 16/12/2023.
//

#include "FindDuplicatesRequestHandler.h"

FindDuplicatesResponse* FindDuplicatesRequestHandler::handleRequest(const FindDuplicatesRequest& request) {
    auto files = retrieveFilesRecursively(request);
    auto targetFile = FileEntry(request.targetFilePath());

    std::vector<FileEntry *> duplicateFiles;
    std::ranges::copy_if(
        files,
        std::back_inserter(duplicateFiles),
        [&targetFile](FileEntry* f) {
            return f->name() == targetFile.name() && f->size() == targetFile.size();
        });

    return new FindDuplicatesResponse(duplicateFiles, files);
}
