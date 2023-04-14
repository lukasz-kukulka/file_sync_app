#pragma once
#include "Stats.hpp"

#include "nlohmann/json.hpp"
#include <fstream>
#include <string>
#include <filesystem>

namespace fs = std::filesystem;
using json = nlohmann::json;

class Synchronizer {
public:
    Synchronizer( std::string const& main_path, std::string const& default_setting_path );

    std::string getMachinePath() const;
    SyncApp::DefaultSettingsInfo getDefaultSettingsFromFile() const;
private:
    void loadDefaultSettingsFromFile();
    void saveDefaultSettingsToFile();
    void setMachinesPath();
    
    std::string default_setting_path_{};
    std::string main_path_{};
    std::string machines_path_{};
    SyncApp::DefaultSettingsInfo default_settings_{};
};