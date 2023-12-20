//
// Created by Nikita Karalyus on 17/12/2023.
//

#ifndef INVALIDFORMATEXCEPTION_H
#define INVALIDFORMATEXCEPTION_H

#include "ApplicationException.h"

class InvalidFormatException final : public ApplicationException {
public:
    explicit InvalidFormatException(const std::string& message)
        : ApplicationException(message) { }
};

#endif //INVALIDFORMATEXCEPTION_H
