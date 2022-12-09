#pragma once

#include <filesystem>

namespace fs = std::filesystem;

class FileInfo {
public:
    FileInfo( fs::directory_entry directory_entry, std::time_t time );
    auto operator<=>(const FileInfo& other) const = default;
private:
    fs::path path_{};
    uint64_t file_size_{};
    std::time_t mod_time_{};
};