//
// Created by Nikita Karalyus on 16/12/2023.
//

#include "ApplicationBuilder.h"

ApplicationBuilder& ApplicationBuilder::addRequestRouter(IRequestRouter* requestRouter) {
    this->requestRouter = requestRouter;
    return *this;
}

ApplicationBuilder& ApplicationBuilder::addUserInteractor(IUserInteractor* userInteractor) {
    this->userInteractor = userInteractor;
    return *this;
}

Application* ApplicationBuilder::build() {
    auto handler = new RequestHandler(this->requestRouter);
    return new Application(handler, userInteractor);
}
