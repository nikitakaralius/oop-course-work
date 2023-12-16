//
// Created by Nikita Karalyus on 16/12/2023.
//

#ifndef QUERYFILESREQUESTHANDLER_H
#define QUERYFILESREQUESTHANDLER_H

#include "QueryFilesRequest.h"
#include "QueryFilesResponse.h"
#include "../../CQRS/Abstractions/IGenericRequestHandler.h"
#include "../../FileSystem/Models/DirectoryEntry/DirectoryEntry.h"


class QueryFilesRequestHandler :
        public IGenericRequestHandler<
            QueryFilesRequest,
            QueryFilesResponse> {
public:
    QueryFilesResponse* handleRequest(const QueryFilesRequest& request) override;

private:
    std::vector<FileEntry*> getFiles(
        const DirectoryEntry& directory,
        int currentDepthLevel,
        int maxDepthLevel) const;
};


#endif //QUERYFILESREQUESTHANDLER_H
