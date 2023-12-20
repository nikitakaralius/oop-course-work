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
    std::vector<FileEntry*> retrieveFilesRecursively(const FilesRequest& request) const;

private:
    std::vector<FileEntry*> retrieveFilesRecursively(
        const DirectoryEntry& directory,
        int currentDepthLevel,
        int maxDepthLevel) const;
};

template<class TRequest, class TResponse>
std::vector<FileEntry*> FilesRequestHandler<TRequest, TResponse>::retrieveFilesRecursively(const FilesRequest& request) const {
    const auto rootDirectory = DirectoryEntry(request.directoryPath());
    return retrieveFilesRecursively(rootDirectory, 1, request.maxDepthLevel());
}

template<class TRequest, class TResponse>
std::vector<FileEntry*> FilesRequestHandler<TRequest, TResponse>::retrieveFilesRecursively(
    const DirectoryEntry& directory,
    const int currentDepthLevel,
    const int maxDepthLevel) const {
    if (currentDepthLevel > maxDepthLevel)
        return {};

    std::vector<FileEntry*> files;
    auto directoryFiles = directory.files();

    files.insert(
        files.end(),
        directoryFiles.begin(),
        directoryFiles.end());

    const auto subdirectories = directory.subdirectories();

    if (subdirectories.empty())
        return files;

    for (const auto subdirectory : subdirectories) {
        auto subdirectoryFiles = retrieveFilesRecursively(
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
