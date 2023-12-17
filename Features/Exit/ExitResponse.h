//
// Created by Nikita Karalyus on 17/12/2023.
//

#ifndef EXITRESPONSE_H
#define EXITRESPONSE_H
#include "../../CQRS/Abstractions/IResponse.h"

class ExitResponse final : public IResponse {
public:
    std::string toString() override {
        return "Приложение успешно остановлено";
    }
};

#endif //EXITRESPONSE_H
