//
// Created by Nikita Karalyus on 16/12/2023.
//

#ifndef LOGGERMIDDLEWARE_H
#define LOGGERMIDDLEWARE_H

#include "../../../CQRS/Abstractions/IMiddleware.h"
#include "../../Abstractions/ILogger.h"


class LoggerMiddleware : public IMiddleware {
public:
    explicit LoggerMiddleware(ILogger* logger)
        : _logger(logger) { }

    ~LoggerMiddleware() override;

    IResponse* invoke(
        IRequest& request,
        std::function<IResponse*(IRequest&)> next) override;

private:
    ILogger* _logger;

};



#endif //LOGGERMIDDLEWARE_H
