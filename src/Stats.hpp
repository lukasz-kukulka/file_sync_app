#pragma once

#include "FileInfo.hpp"

#include <iostream>
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

    enum class CompareOption {
        None,
        Equal,
        Different,
        Greater,
        Less,
    };

    CompareOption getCompareOption( FileInfo* const lhs, FileInfo* const rhs );

    template<typename... Args>
    FileInfo* compareFilesInfo( const Args*... args );
} // namespace SyncApp

