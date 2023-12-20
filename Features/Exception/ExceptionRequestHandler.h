//
// Created by Nikita Karalyus on 17/12/2023.
//

#ifndef EXCEPTIONREQUESTHANDLER_H
#define EXCEPTIONREQUESTHANDLER_H

#include "ExceptionResponse.h"
#include "ExpcetionRequest.h"
#include "../../CQRS/Abstractions/IRequestHandler.h"
#include <vector>


class ExceptionRequestHandler final :
        public IGenericRequestHandler<
            ExceptionRequest,
            ExceptionResponse> {
public:
    ExceptionResponse* handleRequest(const ExceptionRequest& request) override {
        return new ExceptionResponse(request.message());
    }
};

#endif //EXCEPTIONREQUESTHANDLER_H
