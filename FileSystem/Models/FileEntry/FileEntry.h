//
// Created by Nikita Karalyus on 16/12/2023.
//

#ifndef FILEENTRY_H
#define FILEENTRY_H

#include "../../Abstractions/IFileSystemEntry.h"


class FileEntry final : IFileSystemEntry {
public:
    explicit FileEntry(const std::string&path);

    std::string name() override;
    long long size() override;
    time_t updatedAt() override;

    std::string getPath() const { return path;}

private:
    std::string path;
};



#endif //FILEENTRY_H
