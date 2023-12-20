//
// Created by Nikita Karalyus on 16/12/2023.
//

#ifndef IREQUESTHANDLER_H
#define IREQUESTHANDLER_H

#include "IResponse.h"
#include "IRequest.h"

class IRequestHandler {
public:
    virtual ~IRequestHandler() = default;

    virtual IResponse* handle(IRequest& request) = 0;
};

template<class TRequest, class TResponse>
class IGenericRequestHandler : public IRequestHandler {
public:
    virtual TResponse* handleRequest(const TRequest& request) = 0;

    IResponse* handle(IRequest& request) override {
        return handleRequest(dynamic_cast<TRequest&>(request));
    }
};

#endif //IREQUESTHANDLER_H
