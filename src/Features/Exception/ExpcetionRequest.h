//
// Created by Nikita Karalyus on 17/12/2023.
//

#ifndef EXPCETIONREQUEST_H
#define EXPCETIONREQUEST_H

#include "../../CQRS/Abstractions/IRequest.h"

class ExceptionRequest final : public IRequest {
public:
    explicit ExceptionRequest(const std::string& message) : _message(message) {  }

    std::string message() const { return _message; }

    std::string toString() override { return _message; }

private:
    std::string _message;
};

#endif //EXPCETIONREQUEST_H
