#pragma once

#include "FileInfo.hpp"
#include "nlohmann/json.hpp"
#include <chrono>
#include <filesystem>
#include <map>
#include <string>
#include <vector>

using json = nlohmann::json;
namespace fs = std::filesystem;

class Machine {
public:
    Machine( fs::path const& path );
    void saveMachineFilesInfo( json const& json, fs::directory_entry dir_entry );
    std::map< std::string, FileInfo >& getFileInfo();
    std::string getMachineName() const;
    void addNewFileInfo( FileInfo const& file_info );
    std::string getMachinePatch() const;

private:
    void setExistingFileInfo();
    std::string getPathToFile( fs::directory_entry const& file, fs::path const& path );
    std::map< std::string, FileInfo > exist_files_info_;
    std::map< std::string, FileInfo > prev_files_info_;
    std::map< std::string, FileInfo > new_files_info_;
    std::vector< std::unique_ptr< fs::directory_entry > > files_pointers_{};
    fs::path path_{};
    std::string machine_name_{};
};