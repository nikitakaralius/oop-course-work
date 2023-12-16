//
// Created by Nikita Karalyus on 16/12/2023.
//

#ifndef APPLICATIONBUILDER_H
#define APPLICATIONBUILDER_H
#include "../../CQRS/Abstractions/IRequestRouter.h"
#include "../Application/Application.h"


class ApplicationBuilder {
private:
    IRequestRouter* requestRouter;

public:
    static ApplicationBuilder& create() { return *new ApplicationBuilder(); }

    ApplicationBuilder& withRequestRouter(IRequestRouter* requestRouter);

    Application* build();
};



#endif //APPLICATIONBUILDER_H
