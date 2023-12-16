//
// Created by Nikita Karalyus on 16/12/2023.
//

#ifndef COUNTTOTALSIZEREQUESTHANDLER_H
#define COUNTTOTALSIZEREQUESTHANDLER_H

#include "CountTotalSizeRequest.h"
#include "CountTotalSizeResponse.h"
#include "../../CQRS/Abstractions/IGenericRequestHandler.h"


class CountTotalSizeRequestHandler :
        public IGenericRequestHandler<
            CountTotalSizeRequest,
            CountTotalSizeResponse> {
public:
    CountTotalSizeResponse* handleRequest(const CountTotalSizeRequest& request) override;
};


#endif //COUNTTOTALSIZEREQUESTHANDLER_H
