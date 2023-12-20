//
// Created by Nikita Karalyus on 16/12/2023.
//

#ifndef COUNTFILESREQUESTHANDLER_H
#define COUNTFILESREQUESTHANDLER_H

#include <vector>

#include "CountFilesRequest.h"
#include "CountFilesResponse.h"
#include "../Common/FilesRequestHandler.h"


class CountFilesRequestHandler final :
        public FilesRequestHandler<
            CountFilesRequest,
            CountFilesResponse> {
public:
    CountFilesResponse* handleRequest(const CountFilesRequest&request) override;
};


#endif //COUNTFILESREQUESTHANDLER_H
