#pragma once

#include <filesystem>
#include <string>
namespace fs = std::filesystem;

class FileInfo {
public:
    FileInfo( fs::directory_entry const& file );
    std::time_t getModTime( ) const;
private:
    std::time_t getFileTime( fs::directory_entry file ) const;
    void setFileTime( fs::directory_entry file );
    std::string path_{};
    uint64_t mod_time_{};
    uint64_t file_size_{};
    
};