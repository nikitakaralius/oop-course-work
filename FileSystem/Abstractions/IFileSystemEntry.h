//
// Created by Nikita Karalyus on 16/12/2023.
//

#ifndef IFILESYSTEMENTRY_H
#define IFILESYSTEMENTRY_H

#include <string>

#include "../Models/DateTime/DateTime.h"

class IFileSystemEntry {
public:
    virtual ~IFileSystemEntry() = default;

    virtual std::string name() = 0;
    virtual long long size() = 0;
    virtual DateTime createdAt() = 0;
};

#endif //IFILESYSTEMENTRY_H
