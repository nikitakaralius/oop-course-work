//
// Created by Nikita Karalyus on 16/12/2023.
//

#include "ApplicationRequestRouter.h"

#include "../../../Features/CountDirectories/CountDirectoriesRequest.h"
#include "../../../Features/CountDirectories/CountDirectoriesRequestHandler.h"
#include "../../../Features/Mock/MockRequest.h"
#include "../../../Features/Mock/MockRequestHandler.h"

IRequestHandler* ApplicationRequestRouter::getHandler(IRequest& request) {
    if (dynamic_cast<MockRequest*>(&request))
        return new MockRequestHandler();

    if (dynamic_cast<CountDirectoriesRequest*>(&request))
        return new CountDirectoriesRequestHandler();

    throw std::runtime_error("not yet implemeted");
}
