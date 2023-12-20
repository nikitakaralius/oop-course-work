//
// Created by Nikita Karalyus on 16/12/2023.
//

#ifndef LARGESTFILESREQUESTHANDLER_H
#define LARGESTFILESREQUESTHANDLER_H

#include "LargestFilesRequest.h"
#include "LargestFilesResponse.h"
#include "../Common/FilesRequestHandler.h"

class LargestFilesRequestHandler final :
        public FilesRequestHandler<
            LargestFilesRequest,
            LargestFilesResponse> {
public:
    LargestFilesResponse* handleRequest(const LargestFilesRequest& request) override;
};



#endif //LARGESTFILESREQUESTHANDLER_H
