//
// Created by Nikita Karalyus on 16/12/2023.
//

#ifndef FINDDUPLICATESREQUESTHANDLER_H
#define FINDDUPLICATESREQUESTHANDLER_H

#include "FindDuplicatesRequest.h"
#include "FindDuplicatesResponse.h"
#include "../Common/FilesRequestHandler.h"

class FindDuplicatesRequestHandler final :
        public FilesRequestHandler<
            FindDuplicatesRequest,
            FindDuplicatesResponse> {
public:
    FindDuplicatesResponse* handleRequest(const FindDuplicatesRequest& request) override;
};



#endif //FINDDUPLICATESREQUESTHANDLER_H
