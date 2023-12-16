//
// Created by Nikita Karalyus on 16/12/2023.
//

#include "FileEntry.h"

#include <__filesystem/operations.h>

namespace fs = std::filesystem;

FileEntry::FileEntry(std::string path) {
    if (!fs::exists(path))
        throw std::runtime_error("File " + path + " does not exist");

    this->path = path;
}

std::string FileEntry::name() {
    return fs::path(path).filename();
}

long long FileEntry::size() {
    return fs::file_size(path);
}

DateTime FileEntry::createdAt() {
    auto lastWriteTime = fs::last_write_time(path);
    return DateTime(lastWriteTime.time_since_epoch().count());
}
