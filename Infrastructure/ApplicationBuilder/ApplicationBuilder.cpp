//
// Created by Nikita Karalyus on 16/12/2023.
//

#include "ApplicationBuilder.h"

ApplicationBuilder& ApplicationBuilder::withRequestRouter(IRequestRouter* requestRouter) {
    this->requestRouter = requestRouter;
    return *this;
}

Application* ApplicationBuilder::build() {
    auto handler = new RequestHandler(this->requestRouter);
    return new Application(handler);
}
