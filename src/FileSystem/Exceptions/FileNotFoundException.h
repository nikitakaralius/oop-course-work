//
// Created by Nikita Karalyus on 17/12/2023.
//

#ifndef FILENOTFOUNDEXCEPTION_H
#define FILENOTFOUNDEXCEPTION_H

#include "ApplicationException.h"

class FileNotFoundException final : public ApplicationException {
public:
    explicit FileNotFoundException(const std::string& message)
        : ApplicationException(message) { }
};


#endif //FILENOTFOUNDEXCEPTION_H
