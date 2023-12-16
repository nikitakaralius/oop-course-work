//
// Created by Nikita Karalyus on 16/12/2023.
//

#include "MockRequestHandler.h"

#include <iostream>

MockResponse* MockRequestHandler::handleRequest(const MockRequest& request) {
    std::cout << "[Handler] Handling mock request";
    return new MockResponse();
}
