//
// Created by Nikita Karalyus on 16/12/2023.
//

#include "MiddlewarePipeline.h"

MiddlewarePipeline::~MiddlewarePipeline() {
    for (const auto middleware : middlewares) {
        delete middleware;
    }
}

void MiddlewarePipeline::use(IMiddleware* middleware) {
    middlewares.push_back(middleware);
}

IResponse* MiddlewarePipeline::process(IRequest& request) {
    std::function finalHandler = [this](IRequest& r) {
        return requestHandler->handleRequest(r);
    };

    for (auto it = middlewares.rbegin(); it != middlewares.rend(); ++it) {
        finalHandler = [this, middleware = *it, nextHandler = finalHandler](IRequest& r) {
            return middleware->invoke(r, nextHandler);
        };
    }

    return finalHandler(request);
}
