//
// Created by Nikita Karalyus on 16/12/2023.
//

#ifndef MOCKREQUESTHANDLER_H
#define MOCKREQUESTHANDLER_H
#include "MockRequest.h"
#include "MockResponse.h"
#include "../../CQRS/Abstractions/IGenericRequestHandler.h"


class MockRequestHandler final : public IGenericRequestHandler<MockRequest, MockResponse> {
public:
    MockResponse* handleRequest(const MockRequest& request) override;
};



#endif //MOCKREQUESTHANDLER_H
