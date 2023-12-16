//
// Created by Nikita Karalyus on 16/12/2023.
//

#include <filesystem>
#include "CountDirectoriesRequestHandler.h"

#include "../../FileSystem/Models/DirectoryEntry/DirectoryEntry.h"

namespace fs = std::filesystem;

CountDirectoriesResponse* CountDirectoriesRequestHandler::handleRequest(const CountDirectoriesRequest& request) {
    DirectoryEntry rootDirectory(request.getDirectoryPath());

    const int directoryCount = countDirectories(
    rootDirectory,
    1,
    request.getDepthLevel());

    return new CountDirectoriesResponse(directoryCount);
}

int CountDirectoriesRequestHandler::countDirectories(DirectoryEntry& entry, int currrentLevel, int maxLevel) {
    if (currrentLevel >= maxLevel)
        return 0;

    if (entry.subdirectories().empty())
        return 0;

    auto subdirectories = entry.subdirectories();
    int count = subdirectories.size();

    for (auto subdirectory : subdirectories) {
        count += countDirectories(*subdirectory, currrentLevel + 1, maxLevel);
    }

    return count;
}
