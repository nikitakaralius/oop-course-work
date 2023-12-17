//
// Created by Nikita Karalyus on 17/12/2023.
//

#ifndef DIRECTORYNOTFOUNDEXCEPTION_H
#define DIRECTORYNOTFOUNDEXCEPTION_H
#include <stdexcept>

class DirectoryNotFoundException final : public std::runtime_error {
public:
    explicit DirectoryNotFoundException(const std::string& basic_string)
        : runtime_error(basic_string) { }

    explicit DirectoryNotFoundException(const char* string)
        : runtime_error(string) { }

    explicit DirectoryNotFoundException(const runtime_error& runtime_error)
        : runtime_error(runtime_error) { }
};

#endif //DIRECTORYNOTFOUNDEXCEPTION_H
