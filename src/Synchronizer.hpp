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
    std::time_t lastSyncDate{}; 

};
class Synchronizer {
public:
    Synchronizer( std::string const& main_path, std::string const& default_setting_path );

    std::string getMachinePath() const;
    DefaultSettingsInfo getDefaultSettingsFromFile() const;
private:
    void loadDefaultSettingsFromFile();
    void saveDefaultSettingsToFile();
    void setMachinesPath();
    
    std::string default_setting_path_{};
    std::string main_path_{};
    std::string machines_path_{};
    DefaultSettingsInfo default_settings_{};
};