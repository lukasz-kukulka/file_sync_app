#pragma once

#include "FileInfo.hpp"

#include <iostream>
#include <string>
#include <filesystem>
#include <optional>



namespace SyncApp {
    constexpr const char systemInfoInit() {
        #ifdef _WIN32
            return '\\';
        #else
            return '/';
        #endif
    }
    constexpr const char kFilePathSeparator = systemInfoInit();
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
        Unique
    };

    CompareOption getCompareOption( FileInfo* lhs, FileInfo* rhs );

    template< typename... Args >
    FileInfo* compareFilesInfo( Args*... args ) {
        FileInfo* newest_file = nullptr;
        for ( auto info : { args... } ) {
            auto const compare_result = getCompareOption( newest_file, info );
            switch ( compare_result ) {
                case CompareOption::Different :
                    newest_file = info;
                    break;
                case CompareOption::Equal :
                    newest_file = info;
                    break;
                case CompareOption::Greater :
                    // std::cout << "GREATER " << info->getAbsolutePath() << std::endl; 
                    // info->setIsFileToReplace( true );
                    break;
                case CompareOption::Less :
                    // std::cout << "LESS " << info->getAbsolutePath() << std::endl; 
                    // newest_file->setIsFileToReplace( true );
                    newest_file = info;
                    break;
                case CompareOption::Unique :
                    newest_file = nullptr;
                    break;
                default:    
                    std::cerr << "ERROR WRONG VALUE IN COMPARE FUNCTION\n" << std::endl; 
                    newest_file = nullptr;
                    break;
            }
        }
        return newest_file;
    }
} // namespace SyncApp

