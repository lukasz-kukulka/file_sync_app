#pragma once

#include <chrono>
#include <filesystem>
#include <string>
#include <vector>

namespace fs = std::filesystem;

class Machine {
public:
    Machine( fs::path path );
    
private:
    void setFilesPaths();
    std::time_t getFileTime( fs::directory_entry file );
    char* convertToLocalTime( std::time_t const& time );
    void saveMachineFilesInfo();
    void loadMachineFilesInfo();
    std::vector< fs::path > files_status_{};
    fs::path path_{};
    std::string machine_name_{};
};