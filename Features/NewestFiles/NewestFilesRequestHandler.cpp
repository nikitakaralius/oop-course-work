//
// Created by Nikita Karalyus on 16/12/2023.
//

#include "NewestFilesRequestHandler.h"

NewestFilesResponse* NewestFilesRequestHandler::handleRequest(const NewestFilesRequest& request) {
    auto files = retrieveFilesRecursively(request);
    auto timeThreshold = request.timeThreshold();

    std::vector<FileEntry *> largestFiles;
    std::ranges::copy_if(
        files,
        std::back_inserter(largestFiles),
        [timeThreshold](FileEntry* f) {
            return f->updatedAt() >= timeThreshold;
        });

    return new NewestFilesResponse(largestFiles);
}
