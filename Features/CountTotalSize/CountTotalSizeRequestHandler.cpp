//
// Created by Nikita Karalyus on 16/12/2023.
//

#include "CountTotalSizeRequestHandler.h"
#include <numeric>

CountTotalSizeResponse* CountTotalSizeRequestHandler::handleRequest(const CountTotalSizeRequest& request) {
    auto files = getFiles(request);

    const auto totalSize = std::accumulate(
    files.begin(),
    files.end(),
    0l,
    [](long long totalSize, FileEntry* file) {
        return totalSize + file->size();
    });

    return new CountTotalSizeResponse(totalSize);
}
