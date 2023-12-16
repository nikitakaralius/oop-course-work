//
// Created by Nikita Karalyus on 16/12/2023.
//

#ifndef ISTRINGFORMATTABLE_H
#define ISTRINGFORMATTABLE_H

#include <string>

class IStringFormattable {
public:
    virtual ~IStringFormattable() = default;

    virtual std::string toString() = 0;
};

#endif //ISTRINGFORMATTABLE_H
