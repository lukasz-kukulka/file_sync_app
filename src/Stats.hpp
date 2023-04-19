#pragma once

#include "FileInfo.hpp"

#include <iostream>
#include <string>
#include <filesystem>
#include <optional>

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

    //CompareOption getCompareOption( std::optional< FileInfo > const& lhs, FileInfo const& rhs );
    CompareOption getCompareOption( FileInfo* lhs, FileInfo* rhs );

    // template< typename... Args >
    // std::optional< FileInfo > compareFilesInfo( Args&... args ) {
    //     std::optional< FileInfo > newest_file = std::nullopt;
    //     for (FileInfo & info : { args... } ) {
    //         auto const compare_result = getCompareOption( newest_file, info );
    //         switch ( compare_result ) {
    //             case CompareOption::Different :
    //             case CompareOption::Equal :
    //                 return std::nullopt;
    //             case CompareOption::Greater :
    //                 info.setIsFileToReplace( true );
    //                 return newest_file;
    //             case CompareOption::Less :
    //                 newest_file.value().setIsFileToReplace( true );
    //                 return info;
    //             default:    
    //                 std::cout << "ERROR WRONG VALUE IN COMPARE FUNCTION\n"; 
    //                 return std::nullopt;
    //         }
    //     }
    //     return std::nullopt;
    // }

    template< typename... Args >
    FileInfo* compareFilesInfo( Args*... args ) {
        FileInfo* newest_file = nullptr;
        for ( auto info : { args... } ) {
            auto const compare_result = getCompareOption( newest_file, info );
            switch ( compare_result ) {
                case CompareOption::Different :
                case CompareOption::Equal :
                    return nullptr;
                case CompareOption::Greater :
                    info->setIsFileToReplace( true );
                    return newest_file;
                case CompareOption::Less :
                    newest_file->setIsFileToReplace( true );
                    return info;
                default:    
                    std::cout << "ERROR WRONG VALUE IN COMPARE FUNCTION\n"; 
                    return nullptr;
            }
        }
        return nullptr;
    }
} // namespace SyncApp

