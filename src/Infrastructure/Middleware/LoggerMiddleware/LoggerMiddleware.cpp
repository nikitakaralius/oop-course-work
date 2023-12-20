//
// Created by Nikita Karalyus on 16/12/2023.
//

#include "LoggerMiddleware.h"

LoggerMiddleware::~LoggerMiddleware() {
    delete _logger;
}

IResponse* LoggerMiddleware::invoke(
    IRequest& request,
    const std::function<IResponse*(IRequest&)> next) {
    _logger->log(request.toString());
    const auto response = next(request);
    _logger->log(response->toString());
    return response;
}
