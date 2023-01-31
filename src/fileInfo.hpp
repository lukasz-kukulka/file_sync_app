#pragma once

#include <filesystem>
#include <string>
namespace fs = std::filesystem;

class FileInfo {
public:
    FileInfo( fs::directory_entry const& file );
    auto operator<=>(const FileInfo& other) const = default;

private:
    std::time_t getFileTime( fs::directory_entry file );
    std::string name_{};
    uint64_t mod_time_{};
    uint64_t file_size_{};
};