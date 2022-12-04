#pragma once

#include <filesystem>
#include <string>
namespace fs = std::filesystem;

class FileInfo {
public:
    FileInfo( std::string path, uint64_t file_size, uint64_t mod_time );
    auto operator<=>(const FileInfo& other) const = default;
private:
    std::string path_{};
    uint64_t file_size_{};
    uint64_t mod_time_{};
};