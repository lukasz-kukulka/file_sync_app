#pragma once

#include <filesystem>
#include <string>
namespace fs = std::filesystem;

class FileInfo {
public:
    explicit FileInfo( fs::directory_entry const& file, std::string const& path, std::string const& machine_name );
    //explicit FileInfo( uint64_t const& mod_time, std::string const& path, uint64_t const& file_size );
    auto operator<=>(const FileInfo& file_info ) const = default;
    std::time_t getModTime( ) const;
    std::string getAbsolutePath() const;
    uint64_t getFileSize() const;
    std::string getMachineName() const;
    std::string getPath() const;

private:
    void setFileTime( fs::directory_entry file );
    std::string machine_name_{};
    std::string absolute_path_{};
    std::string path_{};
    std::time_t mod_time_{};
    uint64_t file_size_{};
    
};
