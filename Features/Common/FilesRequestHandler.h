//
// Created by Nikita Karalyus on 16/12/2023.
//

#ifndef FILESREQUESTHANDLER_H
#define FILESREQUESTHANDLER_H

#include "../../CQRS/Abstractions/IGenericRequestHandler.h"
#include "../../FileSystem/Models/DirectoryEntry/DirectoryEntry.h"

template<class TRequest, class TResponse>
class FilesRequestHandler :  public IGenericRequestHandler<TRequest, TResponse> {
protected:
    std::vector<FileEntry*> getFiles(
        const DirectoryEntry& directory,
        int currentDepthLevel,
        int maxDepthLevel) const;
};


#endif //FILESREQUESTHANDLER_H
