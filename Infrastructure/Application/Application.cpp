//
// Created by Nikita Karalyus on 16/12/2023.
//

#include "Application.h"

Application::Application(
    RequestHandler* requestHandler,
    IUserInteractor* userInteractor) {
    this->requestHandler = requestHandler;
    this->userInteractor = userInteractor;
    middlewarePipeline = new MiddlewarePipeline(requestHandler);
}

Application::~Application() {
    delete middlewarePipeline;
    delete requestHandler;
    delete userInteractor;
}

void Application::use(IMiddleware* middleware) const {
    middlewarePipeline->use(middleware);
}

void Application::run() const {
    while (!userInteractor->shouldExit()) {
        const auto request = userInteractor->readRequest();
        const auto response = middlewarePipeline->process(*request);

        delete request;
        delete response;
    }
}
