//
// Created by Nikita Karalyus on 16/12/2023.
//

#include "Application.h"

Application::Application(
    RequestHandler* requestHandler,
    IUserInteractor* userInteractor) {
    this->_requestHandler = requestHandler;
    this->_userInteractor = userInteractor;
    _middlewarePipeline = new MiddlewarePipeline(requestHandler);
}

Application::~Application() {
    delete _requestHandler;
    delete _userInteractor;
    delete _middlewarePipeline;
}

void Application::use(IMiddleware* middleware) const {
    _middlewarePipeline->use(middleware);
}

void Application::run() const {
    while (!_userInteractor->shouldExit()) {
        const auto request = _userInteractor->readRequest();
        const auto response = _middlewarePipeline->process(*request);

        delete request;
        delete response;
    }
}
