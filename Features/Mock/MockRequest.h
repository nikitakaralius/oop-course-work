//
// Created by Nikita Karalyus on 16/12/2023.
//

#ifndef MOCKREQUEST_H
#define MOCKREQUEST_H

#include "../../CQRS/Abstractions/IRequest.h"


class MockRequest : public IRequest {
public:
    std::string toString() override {
        return "Hello from MockRequest";
    };
};



#endif //MOCKREQUEST_H
