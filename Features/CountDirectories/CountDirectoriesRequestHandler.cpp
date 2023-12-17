//
// Created by Nikita Karalyus on 16/12/2023.
//

#include <filesystem>
#include "CountDirectoriesRequestHandler.h"

#include "../../FileSystem/Models/DirectoryEntry/DirectoryEntry.h"

namespace fs = std::filesystem;

CountDirectoriesResponse* CountDirectoriesRequestHandler::handleRequest(const CountDirectoriesRequest& request) {
    const DirectoryEntry rootDirectory(request.directoryPath());

    const int directoryCount = countDirectories(
    rootDirectory,
    1,
    request.maxDepthLevel());

    return new CountDirectoriesResponse(directoryCount);
}

int CountDirectoriesRequestHandler::countDirectories(
    const DirectoryEntry& entry,
    const int currrentLevel,
    const int maxLevel) {
    if (currrentLevel > maxLevel)
        return 0;

    const auto subdirectories = entry.subdirectories();

    if (subdirectories.empty())
        return 0;

    int count = subdirectories.size();

    for (const auto subdirectory : subdirectories) {
        count += countDirectories(*subdirectory, currrentLevel + 1, maxLevel);
    }

    return count;
}
