//
// Created by Nikita Karalyus on 16/12/2023.
//

#ifndef MOCKREQUESTHANDLER_H
#define MOCKREQUESTHANDLER_H

#include "../../Abstractions/IRequest.h"
#include "../../Abstractions/IGenericRequestHandler.h"
#include "../../Abstractions/IResponse.h"

class MockRequest final : public IRequest {
public:
    int number = 0;

    std::string toString() override { return "Mock Request";}
};

class MockResponse final : public IResponse {
public:
    std::string result;

    std::string toString() override { return result;}
};


class MockRequestHandler final : public IGenericRequestHandler<MockRequest, MockResponse> {
public:
    MockResponse* handleRequest(const MockRequest& request) override;
};



#endif //MOCKREQUESTHANDLER_H
