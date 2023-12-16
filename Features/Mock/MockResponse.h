//
// Created by Nikita Karalyus on 16/12/2023.
//

#ifndef MOCKRESPONSE_H
#define MOCKRESPONSE_H


#include "../../CQRS/Abstractions/IResponse.h"

class MockResponse : public IResponse {
public:
    std::string toString() override {
        return "Hello from MockResponse";
    };
};

#endif //MOCKRESPONSE_H
