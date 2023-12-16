//
// Created by Nikita Karalyus on 16/12/2023.
//

#include "NewestFilesRequestHandler.h"

NewestFilesResponse* NewestFilesRequestHandler::handleRequest(const NewestFilesRequest& request) {
    auto files = getFiles(request);
    auto timeThreshold = request.getTimeThreshold();

    std::vector<FileEntry *> largestFiles;
    std::ranges::copy_if(
        files,
        std::back_inserter(largestFiles),
        [timeThreshold](FileEntry* f) {
            return f->createdAt() >= timeThreshold;
        });

    return new NewestFilesResponse(largestFiles);
}
