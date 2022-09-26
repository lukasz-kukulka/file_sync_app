#pragma once

#include <filesystem>
#include <string>
namespace fs = std::filesystem;

class FileInfo {
public:
    explicit FileInfo( fs::directory_entry const& file );
    explicit FileInfo( uint64_t const& mod_time, std::string const& path, uint64_t const& file_size );
    std::time_t getModTime( ) const;
    std::string getPath() const;
    
private:
    void setFileTime( fs::directory_entry file );
    std::string path_{};
    uint64_t mod_time_{};
    uint64_t file_size_{};
    
};
