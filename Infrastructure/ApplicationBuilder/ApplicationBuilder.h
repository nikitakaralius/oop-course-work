//
// Created by Nikita Karalyus on 16/12/2023.
//

#ifndef APPLICATIONBUILDER_H
#define APPLICATIONBUILDER_H
#include "../../CQRS/Abstractions/IRequestRouter.h"
#include "../Abstractions/IUserInteractor.h"
#include "../Application/Application.h"


class ApplicationBuilder {
private:
    IRequestRouter* requestRouter;
    IUserInteractor* userInteractor;

public:
    static ApplicationBuilder create() { return {}; }

    ApplicationBuilder addRequestRouter(IRequestRouter* requestRouter);

    ApplicationBuilder addUserInteractor(IUserInteractor* userInteractor);

    Application* build();
};



#endif //APPLICATIONBUILDER_H
