//
// Created by Nikita Karalyus on 16/12/2023.
//

#ifndef IREQUESTROUTER_H
#define IREQUESTROUTER_H

#include "IRequest.h"
#include "IRequestHandler.h"
#include "IResponse.h"

class IRequestRouter {
public:
    virtual ~IRequestRouter() = default;

    virtual IRequestHandler<IRequest, IResponse>* getHandler(const IRequest& request) = 0;
};

#endif //IREQUESTROUTER_H
