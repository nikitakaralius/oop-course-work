//
// Created by Nikita Karalyus on 16/12/2023.
//

#ifndef NEWESTFILESREQUESTHANDLER_H
#define NEWESTFILESREQUESTHANDLER_H
#include "NewestFilesRequest.h"
#include "NewestFilesResponse.h"
#include "../Common/FilesRequestHandler.h"


class NewestFilesRequestHandler final :
        public FilesRequestHandler<
            NewestFilesRequest,
            NewestFilesResponse> {
public:
    NewestFilesResponse* handleRequest(const NewestFilesRequest& request) override;
};



#endif //NEWESTFILESREQUESTHANDLER_H
