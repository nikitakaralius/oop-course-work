//
// Created by Nikita Karalyus on 16/12/2023.
//

#include "FilesRequestHandler.h"

template<class TRequest, class TResponse>
std::vector<FileEntry*> FilesRequestHandler<TRequest, TResponse>::getFiles(
    const DirectoryEntry& directory,
    int currentDepthLevel,
    int maxDepthLevel) const {
    if (currentDepthLevel > maxDepthLevel)
        return {};

    std::vector<FileEntry*> files;
    auto directoryFiles = directory.files();

    files.insert(
        files.end(),
        directoryFiles.begin(),
        directoryFiles.end());

    auto subdirectories = directory.subdirectories();

    if (subdirectories.empty())
        return files;

    for (const auto subdirectory : subdirectories) {
        auto subdirectoryFiles = getFiles(
            *subdirectory,
            currentDepthLevel + 1,
            maxDepthLevel);

        files.insert(
            files.end(),
            subdirectoryFiles.begin(),
            subdirectoryFiles.end());
    }

    return files;
}