//
// Created by Nikita Karalyus on 16/12/2023.
//

#include "DirectoryEntry.h"

#include <__filesystem/directory_iterator.h>

std::string DirectoryEntry::name() {
    return "";
}

long long DirectoryEntry::size() {
    return 0;
}

DateTime DirectoryEntry::createdAt() {
    auto lastWriteTime = std::filesystem::last_write_time(path);
    return DateTime(lastWriteTime.time_since_epoch().count());
}

std::vector<DirectoryEntry*>* DirectoryEntry::subdirectories() const {
    auto* subdirs = new std::vector<DirectoryEntry*>;

    for (const auto& entry : std::filesystem::directory_iterator(path)) {
        if (entry.is_directory()) continue;

        subdirs->push_back(new DirectoryEntry(entry.path().string()));
    }

    return subdirs;
}

std::vector<FileEntry*>* DirectoryEntry::files() const {
    auto* files = new std::vector<FileEntry *>;

    for (const auto&entry: std::filesystem::directory_iterator(path)) {
        if (!entry.is_regular_file()) continue;

        files->push_back(new FileEntry(entry.path().string()));
    }

    return files;
}
