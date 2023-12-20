//
// Created by Nikita Karalyus on 17/12/2023.
//

#ifndef DIRECTORYNOTFOUNDEXCEPTION_H
#define DIRECTORYNOTFOUNDEXCEPTION_H

#include "ApplicationException.h"

class DirectoryNotFoundException final : public ApplicationException {
public:
    explicit DirectoryNotFoundException(const std::string& message)
        : ApplicationException(message) { }
};

#endif //DIRECTORYNOTFOUNDEXCEPTION_H
