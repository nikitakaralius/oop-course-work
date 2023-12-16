//
// Created by Nikita Karalyus on 16/12/2023.
//

#ifndef DIRECTORYENTRY_H
#define DIRECTORYENTRY_H

#include <utility>
#include <__filesystem/path.h>

#include "../../Abstractions/IFileSystemEntry.h"
#include "../FileEntry/FileEntry.h"

namespace fs = std::filesystem;


class DirectoryEntry final : public IFileSystemEntry {
public:
    explicit DirectoryEntry(std::string path) : path(std::move(path)) { }

    std::string name() override;
    long long size() override;
    time_t createdAt() override;

    std::vector<DirectoryEntry*> subdirectories() const;
    std::vector<FileEntry*> files() const;

private:
    std::string path;

    long long size(const fs::path& directoryPath) const;
};



#endif //DIRECTORYENTRY_H
