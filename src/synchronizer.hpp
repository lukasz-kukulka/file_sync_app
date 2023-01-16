#pragma once
#include "nlohmann/json.hpp"
#include <fstream>
#include <string>
#include <filesystem>

namespace fs = std::filesystem;

using json = nlohmann::json;

struct DefaultSettingsInfo {
    std::string machineDirectory{};
    bool isDeleteSync{};
    std::time_t syncTime{};
    std::string machineSettingsFile{};
};
class Synchronizer {
public:
    Synchronizer( std::string  main_path );

    std::string getMachinePath() const;
private:
    void setMachinesPath();
    std::string getParsedSettings( std::string const& path, std::string const& settings_name );
    std::string main_path_{};
    std::string machines_path_{};
};