//
// Created by Nikita Karalyus on 17/12/2023.
//

#ifndef EXCEPTIONRESPONSE_H
#define EXCEPTIONRESPONSE_H

#include <sstream>
#include "../../CQRS/Abstractions/IResponse.h"

class ExceptionResponse final : public IResponse {
public:
    explicit ExceptionResponse(const std::string& message) : _message(message) {  }

    std::string toString() override {
        std::stringstream ss;
        ss << "В процессе работы программы возникла ошибка: " << _message;
        return ss.str();
    }

private:
    std::string _message;
};

#endif //EXCEPTIONRESPONSE_H
