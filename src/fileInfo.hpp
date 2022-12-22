#pragma once

#include <filesystem>

namespace fs = std::filesystem;

class FileInfo {
public:
    FileInfo( fs::directory_entry directory_entry );
    
private:
    std::time_t system_time_;
    fs::directory_entry directory_entry_{};
};