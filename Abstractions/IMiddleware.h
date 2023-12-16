//
// Created by Nikita Karalyus on 16/12/2023.
//

#ifndef IMIDDLEWARE_H
#define IMIDDLEWARE_H

#include "IRequest.h"
#include "IResponse.h"

#include "../Include/Aliases.h"

class IMiddleware {
public:
    virtual ~IMiddleware() = default;

    virtual IResponse* invoke(
        const IRequest&request,
        RequestDelegate next) = 0;
};

#endif //IMIDDLEWARE_H
