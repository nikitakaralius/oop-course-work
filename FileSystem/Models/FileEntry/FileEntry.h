//
// Created by Nikita Karalyus on 16/12/2023.
//

#ifndef FILEENTRY_H
#define FILEENTRY_H

#include <utility>
#include "../../Abstractions/IFileSystemEntry.h"


class FileEntry final : IFileSystemEntry {
public:
    explicit FileEntry(std::string path);

    std::string name() override;
    long long size() override;
    time_t createdAt() override;

private:
    std::string _name;
    long long _size;
    time_t _createdAt;
};



#endif //FILEENTRY_H
