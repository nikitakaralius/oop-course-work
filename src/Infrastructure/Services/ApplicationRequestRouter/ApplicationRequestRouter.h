//
// Created by Nikita Karalyus on 16/12/2023.
//

#ifndef APPLICATIONREQUESTROUTER_H
#define APPLICATIONREQUESTROUTER_H

#include "../../../CQRS/Abstractions/IRequestRouter.h"


class ApplicationRequestRouter final : public IRequestRouter {
public:
    IRequestHandler* getHandler(IRequest& request) override;
};



#endif //APPLICATIONREQUESTROUTER_H
