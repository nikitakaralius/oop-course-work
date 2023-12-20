//
// Created by Nikita Karalyus on 17/12/2023.
//

#ifndef APPLICATIONEXCEPTION_H
#define APPLICATIONEXCEPTION_H
#include <exception>
#include <string>

class ApplicationException : public std::exception {
public:
    explicit ApplicationException(const std::string& message) : _message(message) {  }

    std::string message() const { return _message; }
private:
    std::string _message;
};

#endif //APPLICATIONEXCEPTION_H
