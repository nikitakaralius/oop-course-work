//
// Created by Nikita Karalyus on 16/12/2023.
//

#ifndef DEFAULTREQUESTROUTER_H
#define DEFAULTREQUESTROUTER_H

#include "../../Abstractions/IRequestRouter.h"

class DefaultRequestRouter final : public IRequestRouter {
public:
    IRequestHandler* getHandler(IRequest& request) override;
};



#endif //DEFAULTREQUESTROUTER_H
