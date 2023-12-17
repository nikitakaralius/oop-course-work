//
// Created by Nikita Karalyus on 17/12/2023.
//

#ifndef EXCEPTIONHANDLINGMIDDLEWARE_H
#define EXCEPTIONHANDLINGMIDDLEWARE_H

#include "../../../CQRS/Abstractions/IMiddleware.h"


class ExceptionHandlingMiddleware final : public IMiddleware {
public:
    IResponse* invoke(IRequest& request, std::function<IResponse*(IRequest&)> next) override;
};



#endif //EXCEPTIONHANDLINGMIDDLEWARE_H
