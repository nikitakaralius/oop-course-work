//
// Created by Nikita Karalyus on 16/12/2023.
//

#ifndef DIRECTORYENTRY_H
#define DIRECTORYENTRY_H

#include <utility>

#include "../../Abstractions/IFileSystemEntry.h"
#include "../FileEntry/FileEntry.h"


class DirectoryEntry final : public IFileSystemEntry {
public:
    explicit DirectoryEntry(std::string path) : path(std::move(path)) { }

    std::string name() override;
    long long size() override;
    time_t createdAt() override;

    std::vector<DirectoryEntry> subdirectories(int level = 1);
    std::vector<FileEntry> files(int level = 1);

private:
    std::string path;
};



#endif //DIRECTORYENTRY_H
