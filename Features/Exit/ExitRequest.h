//
// Created by Nikita Karalyus on 17/12/2023.
//

#ifndef EXITREQUEST_H
#define EXITREQUEST_H
#include "../../CQRS/Abstractions/IRequest.h"

class ExitRequest final : public IRequest {
public:
    std::string toString() override {
        return "Запрос на выход из приложения";
    }
};

#endif //EXITREQUEST_H
