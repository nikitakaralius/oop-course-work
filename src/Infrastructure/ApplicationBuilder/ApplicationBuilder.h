//
// Created by Nikita Karalyus on 16/12/2023.
//

#ifndef APPLICATIONBUILDER_H
#define APPLICATIONBUILDER_H

#include "../../CQRS/Abstractions/IRequestRouter.h"
#include "../Abstractions/IUserInteractor.h"
#include "../Application/Application.h"


class ApplicationBuilder {
public:
    static ApplicationBuilder create() { return {}; }

    ApplicationBuilder addRequestRouter(IRequestRouter* requestRouter);

    ApplicationBuilder addUserInteractor(IUserInteractor* userInteractor);

    Application* build();

private:
    IRequestRouter* _requestRouter{};
    IUserInteractor* _userInteractor{};
};



#endif //APPLICATIONBUILDER_H
