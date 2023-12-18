//
// Created by Nikita Karalyus on 16/12/2023.
//

#include "CountTotalSizeRequestHandler.h"
#include <numeric>

CountTotalSizeResponse* CountTotalSizeRequestHandler::handleRequest(const CountTotalSizeRequest& request) {
    auto files = retrieveFilesRecursively(request);

    const auto totalSize = std::accumulate(
    files.begin(),
    files.end(),
    0l,
    [](const long long size, FileEntry* file) {
        return size + file->size();
    });

    for (const auto file : files)
        delete file;

    return new CountTotalSizeResponse(totalSize);
}
