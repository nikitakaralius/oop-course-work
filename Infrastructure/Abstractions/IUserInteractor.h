//
// Created by Nikita Karalyus on 16/12/2023.
//

#ifndef IUSERINTERACTOR_H
#define IUSERINTERACTOR_H
#include "../../Features/Mock/MockRequest.h"

class IUserInteractor {
public:
    virtual ~IUserInteractor() = default;

    virtual bool shouldExit() = 0;

    virtual IRequest* readRequest() = 0;
};

#endif //IUSERINTERACTOR_H
