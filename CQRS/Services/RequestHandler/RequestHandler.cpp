//
// Created by Nikita Karalyus on 16/12/2023.
//

#include "RequestHandler.h"

IResponse* RequestHandler::handleRequest(IRequest& request) const {
    const auto handler = router->getHandler(request);
    const auto response = handler->handle(request);
    delete handler;
    return response;
}
