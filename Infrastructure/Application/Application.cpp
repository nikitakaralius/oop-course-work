//
// Created by Nikita Karalyus on 16/12/2023.
//

#include "Application.h"

Application::Application(RequestHandler* requestHandler) {
    this->requestHandler = requestHandler;
    middlewarePipeline = new MiddlewarePipeline(requestHandler);
}

Application::~Application() {
    delete middlewarePipeline;
    delete requestHandler;
}

void Application::use(IMiddleware* middleware) const {
    middlewarePipeline->use(middleware);
}

void Application::run() const {

}
