//
// Created by Nikita Karalyus on 16/12/2023.
//

#ifndef DIRECTORYENTRY_H
#define DIRECTORYENTRY_H

#include <filesystem>
#include <vector>

#include "../../Abstractions/IFileSystemEntry.h"
#include "../../Exceptions/DirectoryNotFoundException.h"
#include "../FileEntry/FileEntry.h"

namespace fs = std::filesystem;


class DirectoryEntry final : public IFileSystemEntry {
public:
    explicit DirectoryEntry(const std::string& path) {
        _path = path;

        if (!fs::exists(path))
            throw DirectoryNotFoundException("Директория " + path + " не существует");
    }

    std::string name() override;
    long long size() override;
    time_t updatedAt() override;

    std::vector<DirectoryEntry*> subdirectories() const;
    std::vector<FileEntry*> files() const;

private:
    std::string _path;

    long long size(const fs::path& directoryPath) const;
};



#endif //DIRECTORYENTRY_H
