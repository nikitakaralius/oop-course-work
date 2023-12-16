//
// Created by Nikita Karalyus on 16/12/2023.
//

#include "ApplicationRequestRouter.h"

#include "../../../Features/Mock/MockRequest.h"
#include "../../../Features/Mock/MockRequestHandler.h"

IRequestHandler* ApplicationRequestRouter::getHandler(IRequest& request) {
    if (dynamic_cast<MockRequest*>(&request)) {
        return new MockRequestHandler();
    }

    throw std::runtime_error("not yet implemeted");
}
