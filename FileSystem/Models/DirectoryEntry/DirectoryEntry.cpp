//
// Created by Nikita Karalyus on 16/12/2023.
//

#include "DirectoryEntry.h"
#include <__filesystem/directory_iterator.h>

#include <filesystem>

namespace fs = std::filesystem;

std::string DirectoryEntry::name() {
    return fs::path(path).filename();
}

long long DirectoryEntry::size() {
    return size(path);
}

time_t DirectoryEntry::createdAt() {
    fs::file_time_type lastWriteTime = fs::last_write_time(path);
    return to_time_t(lastWriteTime);
}

std::vector<DirectoryEntry*> DirectoryEntry::subdirectories() const {
    auto subdirs = std::vector<DirectoryEntry*>();

    for (const auto& entry : fs::directory_iterator(path)) {
        if (!entry.is_directory()) continue;

        subdirs.push_back(new DirectoryEntry(entry.path().string()));
    }

    return subdirs;
}

std::vector<FileEntry*> DirectoryEntry::files() const {
    auto files = std::vector<FileEntry *>();

    for (const auto&entry: fs::directory_iterator(path)) {
        if (!entry.is_regular_file()) continue;

        files.push_back(new FileEntry(entry.path().string()));
    }

    return files;
}

long long DirectoryEntry::size(const fs::path& directoryPath) const {
    long long size = 0;
    for (const auto& entry : fs::recursive_directory_iterator(directoryPath)) {
        if (is_regular_file(entry.path())) {
            size += file_size(entry.path());
        }
    }
    return size;
}
