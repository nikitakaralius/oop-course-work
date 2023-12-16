//
// Created by Nikita Karalyus on 16/12/2023.
//

#include "LoggerMiddleware.h"

LoggerMiddleware::~LoggerMiddleware() {
    delete logger;
}

IResponse* LoggerMiddleware::invoke(
    IRequest& request,
    std::function<IResponse*(IRequest&)> next) {
    logger->log(request.toString());
    const auto response = next(request);
    logger->log(response->toString());
    return response;
}
