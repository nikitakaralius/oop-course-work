//
// Created by Nikita Karalyus on 16/12/2023.
//

#ifndef IREQUESTSENDER_H
#define IREQUESTSENDER_H

#include "IRequest.h"

class IRequestSender {
public:
    virtual ~IRequestSender() = default;

    virtual void send(const IRequest& request) = 0;
};

#endif //IREQUESTSENDER_H
