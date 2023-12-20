//
// Created by Nikita Karalyus on 16/12/2023.
//

#ifndef REQUESTHANDLER_H
#define REQUESTHANDLER_H

#include "../../Abstractions/IRequestRouter.h"


class RequestHandler {
public:
    explicit RequestHandler(IRequestRouter* router)
        : _router(router) {}

    IResponse* handleRequest(IRequest& request) const;

private:
    IRequestRouter* _router;
};



#endif //REQUESTHANDLER_H
