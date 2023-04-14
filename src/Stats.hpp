#pragma once

#include <string>
#include <filesystem>

namespace SyncApp {
    struct DefaultSettingsInfo {
        std::string machineDirectory{};
        bool isPreviouslySetings{};
        std::time_t syncTime{};
        std::string machineSettingsFile{};
        std::time_t lastSyncDate{}; 
    };

    enum class MenuOption {
        None,
        SyncMachines,
        Settings,
        Exit
    };
}

