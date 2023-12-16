//
// Created by Nikita Karalyus on 17/12/2023.
//

#ifndef EXITREQUESTHANDLER_H
#define EXITREQUESTHANDLER_H

#include "ExitRequest.h"
#include "ExitResponse.h"
#include "../../CQRS/Abstractions/IGenericRequestHandler.h"

class ExitRequestHandler : public IGenericRequestHandler<ExitRequest, ExitResponse> {
public:
    ExitResponse* handleRequest(const ExitRequest& request) override {
        return new ExitResponse;
    };
};

#endif //EXITREQUESTHANDLER_H
