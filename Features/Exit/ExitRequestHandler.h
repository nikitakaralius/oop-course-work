//
// Created by Nikita Karalyus on 17/12/2023.
//

#ifndef EXITREQUESTHANDLER_H
#define EXITREQUESTHANDLER_H

#include "ExitRequest.h"
#include "ExitResponse.h"
#include "../../CQRS/Abstractions/IRequestHandler.h"

class ExitRequestHandler final : public IGenericRequestHandler<ExitRequest, ExitResponse> {
public:
    ExitResponse* handleRequest(const ExitRequest& request) override {
        return new ExitResponse;
    }
};

#endif //EXITREQUESTHANDLER_H
