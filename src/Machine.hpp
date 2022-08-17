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
    Machine( fs::path const& path );
    //std::vector< std::unique_ptr< fs::directory_entry > > getAllMachineFiles();
    void loadPreviouslyFilesInfo( json const& json, std::string const& machine_name );
    void saveMachineFilesInfo( json const& json, fs::directory_entry dir_entry );
    std::vector< FileInfo > const& getFileInfo() const;
private:
    void setExistingFileInfo();
    std::string getPathToFile( fs::directory_entry const& file, fs::path const& path );
    std::vector< FileInfo > exist_files_info_;
    std::vector< FileInfo > prev_files_info_;
    std::vector< FileInfo > new_files_info_;
    std::vector< std::unique_ptr< fs::directory_entry > > files_pointers_{};
    fs::path path_{};
    std::string machine_name_{};
};