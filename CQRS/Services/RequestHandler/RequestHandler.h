//
// Created by Nikita Karalyus on 16/12/2023.
//

#ifndef REQUESTHANDLER_H
#define REQUESTHANDLER_H

#include "../../Abstractions/IRequestRouter.h"


class RequestHandler {
private:
    IRequestRouter* router;

public:
    explicit RequestHandler(IRequestRouter* router)
        : router(router) {}

    IResponse* handleRequest(IRequest& request) const;
};



#endif //REQUESTHANDLER_H
