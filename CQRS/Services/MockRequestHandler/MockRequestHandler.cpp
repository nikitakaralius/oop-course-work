//
// Created by Nikita Karalyus on 16/12/2023.
//

#include "MockRequestHandler.h"

MockResponse* MockRequestHandler::handleRequest(const MockRequest& request) {
    auto response = new MockResponse();
    response->result = "Test";
    return response;
}
