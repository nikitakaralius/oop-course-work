//
// Created by Nikita Karalyus on 16/12/2023.
//

#ifndef DIRECTORYENTRY_H
#define DIRECTORYENTRY_H

#include <utility>

#include "../../Abstractions/IFileSystemEntry.h"
#include "../DateTime/DateTime.h"
#include "../FileEntry/FileEntry.h"


class DirectoryEntry final : public IFileSystemEntry {
public:
    explicit DirectoryEntry(std::string path) : path(std::move(path)) { }

    std::string name() override;
    long long size() override;
    DateTime createdAt() override;

    std::vector<DirectoryEntry*> subdirectories() const;
    std::vector<FileEntry*> files() const;

private:
    std::string path;
};



#endif //DIRECTORYENTRY_H
