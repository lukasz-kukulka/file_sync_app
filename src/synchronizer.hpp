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
    DefaultSettingsInfo DefaultSettingsFromFile() const;
private:
    void setDefaultSettingsFromFile();
    void setMachinesPath();
    
    std::string main_path_{};
    std::string machines_path_{};
    DefaultSettingsInfo default_settings_{};
};