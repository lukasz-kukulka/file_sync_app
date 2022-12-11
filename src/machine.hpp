#pragma once

#include "fileInfo.hpp"
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
    void saveMachineInfo();
    void loadMachineInfo();
    std::vector< FileInfo > files_status_{};
    fs::path path_{};
};