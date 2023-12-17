//
// Created by Nikita Karalyus on 16/12/2023.
//

#ifndef FILESREQUESTHANDLER_H
#define FILESREQUESTHANDLER_H

#include "FilesRequest.h"
#include "../../CQRS/Abstractions/IRequestHandler.h"
#include "../../FileSystem/Models/DirectoryEntry/DirectoryEntry.h"

template<class TRequest, class TResponse>
class FilesRequestHandler :  public IGenericRequestHandler<TRequest, TResponse> {
protected:
    std::vector<FileEntry*> getFiles(const FilesRequest& request) const;

private:
    std::vector<FileEntry*> getFiles(
        const DirectoryEntry& directory,
        int currentDepthLevel,
        int maxDepthLevel) const;
};

template<class TRequest, class TResponse>
std::vector<FileEntry*> FilesRequestHandler<TRequest, TResponse>::getFiles(const FilesRequest& request) const {
    auto rootDirectory = DirectoryEntry(request.getDirectoryPath());
    return getFiles(rootDirectory, 1, request.getMaxDepthLevel());
}

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

#endif //FILESREQUESTHANDLER_H
