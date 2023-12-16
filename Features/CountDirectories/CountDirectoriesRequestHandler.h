//
// Created by Nikita Karalyus on 16/12/2023.
//

#ifndef COUNTDIRECTORIESREQUESTHANDLER_H
#define COUNTDIRECTORIESREQUESTHANDLER_H

#include "CountDirectoriesRequest.h"
#include "CountDirectoriesResponse.h"
#include "../../CQRS/Abstractions/IGenericRequestHandler.h"
#include "../../FileSystem/Models/DirectoryEntry/DirectoryEntry.h"


class CountDirectoriesRequestHandler final :
        public IGenericRequestHandler<
            CountDirectoriesRequest,
            CountDirectoriesResponse> {
public:
    CountDirectoriesResponse* handleRequest(const CountDirectoriesRequest& request) override;

private:
    int countDirectories(DirectoryEntry& entry, int currrentLevel, int maxLevel);
};


#endif //COUNTDIRECTORIESREQUESTHANDLER_H
