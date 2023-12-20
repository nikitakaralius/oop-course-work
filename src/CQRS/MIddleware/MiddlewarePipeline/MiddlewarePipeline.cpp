//
// Created by Nikita Karalyus on 16/12/2023.
//

#include "MiddlewarePipeline.h"

MiddlewarePipeline::~MiddlewarePipeline() {
    for (const auto middleware : _middlewares) {
        delete middleware;
    }
}

void MiddlewarePipeline::use(IMiddleware* middleware) {
    _middlewares.push_back(middleware);
}

IResponse* MiddlewarePipeline::process(IRequest& request) {
    std::function lastHandler = [this](IRequest& r) {
        return _requestHandler->handleRequest(r);
    };

    for (auto it = _middlewares.rbegin(); it != _middlewares.rend(); ++it) {
        lastHandler = [this, middleware = *it, nextHandler = lastHandler](IRequest& r) {
            return middleware->invoke(r, nextHandler);
        };
    }

    return lastHandler(request);
}
