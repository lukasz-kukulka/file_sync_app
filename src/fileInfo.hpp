#pragma once

#include <filesystem>

namespace fs = std::filesystem;

class FileInfo {
public:
    FileInfo( fs::directory_entry directory_entry);
    auto operator<=>( const FileInfo& lhs ) const = default;
private:
    std::time_t setSystemTime( fs::file_time_type const& ftime );

    std::time_t system_time_{};
    fs::directory_entry directory_entry_{};
};