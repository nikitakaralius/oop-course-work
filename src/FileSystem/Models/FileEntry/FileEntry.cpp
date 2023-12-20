//
// Created by Nikita Karalyus on 16/12/2023.
//

#include "FileEntry.h"
#include <filesystem>
#include "../../Exceptions/FileNotFoundException.h"

namespace fs = std::filesystem;

FileEntry::FileEntry(const std::string& path) {
    if (!fs::exists(path))
        throw FileNotFoundException("File " + path + " does not exist");

    this->path = path;
}

std::string FileEntry::name() {
    return fs::path(path).filename();
}

long long FileEntry::size() {
    return fs::file_size(path);
}

time_t FileEntry::updatedAt() {
    const auto updatedAt = fs::last_write_time(path);
    return toTimeT(updatedAt);
}
