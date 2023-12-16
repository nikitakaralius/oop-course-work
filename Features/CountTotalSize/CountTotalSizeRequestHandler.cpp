//
// Created by Nikita Karalyus on 16/12/2023.
//

#include "CountTotalSizeRequestHandler.h"
#include "../QueryFiles/QueryFilesRequestHandler.h"

#include <numeric>

CountTotalSizeResponse* CountTotalSizeRequestHandler::handleRequest(const CountTotalSizeRequest& request) {
    auto queryFilesHandler = QueryFilesRequestHandler();
    auto query = QueryFilesRequest(request.getMaxDepthLevel(), request.getDirectoryPath());
    auto queryFilesResponse = queryFilesHandler.handleRequest(query);

    auto files = queryFilesResponse->getFiles();

    const auto totalSize = std::accumulate(
    files.begin(),
    files.end(),
    0l,
    [](long long totalSize, FileEntry* file) {
        return totalSize + file->size();
    });

    delete queryFilesResponse;

    return new CountTotalSizeResponse(totalSize);
}
