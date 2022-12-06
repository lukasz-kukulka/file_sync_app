#pragma once

#include "fileInfo.hpp"
#include "nlohmann/json.hpp"
#include <chrono>
#include <filesystem>
#include <string>
#include <vector>

using json = nlohmann::json;
namespace fs = std::filesystem;

class Machine {
public:
    Machine( fs::path path );
    void loadPreviouslyFilesInfo( json const& json );
private:
    void setFilesPaths();
    std::time_t getFileTime( fs::directory_entry file );
    char* convertToLocalTime( std::time_t const& time );
    void saveMachineFilesInfo();
    
    std::vector< FileInfo > exist_files_info_{};
    std::vector< FileInfo > prev_files_info_{};
    fs::path path_{};
    std::string machine_name_{};
};