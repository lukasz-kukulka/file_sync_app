#pragma once

#include "FileInfo.hpp"
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
    std::vector< std::unique_ptr< fs::directory_entry > > getAllMachineFiles();
    void loadPreviouslyFilesInfo( json const& json, fs::directory_entry dir_entry );
    void saveMachineFilesInfo( json const& json, fs::directory_entry dir_entry );
private:
    void setFilesPaths();
    char* convertToLocalTime( std::time_t const& time );
    
    
    std::vector< FileInfo > exist_files_info_;
    std::vector< FileInfo > prev_files_info_;
    std::vector< FileInfo > new_files_info_;
    std::vector< std::unique_ptr< fs::directory_entry > > files_pointers_{};
    fs::path path_{};
    std::string machine_name_{};
};