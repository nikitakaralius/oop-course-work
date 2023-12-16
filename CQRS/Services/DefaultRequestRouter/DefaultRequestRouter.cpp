//
// Created by Nikita Karalyus on 16/12/2023.
//

#include "DefaultRequestRouter.h"

#include "../MockRequestHandler/MockRequestHandler.h"

IRequestHandler* DefaultRequestRouter::getHandler(IRequest& request) {
    auto mock_request = dynamic_cast<MockRequest*>(&request);

    if (mock_request) {
        auto handler = new MockRequestHandler();
        return handler;
    }

    throw std::runtime_error("No handler was found");
}
