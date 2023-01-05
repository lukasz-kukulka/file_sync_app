#pragma once
#include "nlohmann/json.hpp"
#include <fstream>
#include <string>
#include <filesystem>

namespace fs = std::filesystem;

using json = nlohmann::json;

class Synchronizer {
public:
    Synchronizer( fs::path main_path );

    //getSettings() const;
private:
    void setMachinesPath();
    std::string getParsedSettings( std::string const& path, std::string const& settings_name );
    fs::path main_path_{};
    std::string machines_path_{};
};