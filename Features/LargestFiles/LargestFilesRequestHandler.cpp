//
// Created by Nikita Karalyus on 16/12/2023.
//

#include "LargestFilesRequestHandler.h"

LargestFilesResponse* LargestFilesRequestHandler::handleRequest(const LargestFilesRequest&request) {
    auto files = getFiles(request);
    auto sizeThreshold = request.getSizeThreshold();

    std::vector<FileEntry *> largestFiles;
    std::ranges::copy_if(
        files,
        std::back_inserter(largestFiles),
        [sizeThreshold](FileEntry* f) {
            return f->size() >= sizeThreshold;
        });

    return new LargestFilesResponse(largestFiles);
}
