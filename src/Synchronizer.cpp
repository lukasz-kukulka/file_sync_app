#include "Synchronizer.hpp"
#include <iostream>
#include <algorithm>
#include <ranges>

Synchronizer::Synchronizer( std::string const& main_path, std::string const& default_setting_path ) 
    : main_path_( main_path )
    , default_setting_path_( default_setting_path )
{
    //std::cout << "AAAAAAAAAAAAc     " << default_setting_path << std::endl;
    loadDefaultSettingsFromFile();
    setMachinesPath();
}

std::string Synchronizer::getMachinePath() const {
    return machines_path_;
}

SyncApp::DefaultSettingsInfo Synchronizer::getDefaultSettingsFromFile() const {
    return default_settings_;
}

void Synchronizer::setMachinesPath() {
    auto const path = main_path_ == "/" ? "" + default_setting_path_ : main_path_ + default_setting_path_;
    //auto const machine_path = main_path_ + default_setting_path_;
    machines_path_ = main_path_ + default_settings_.machineDirectory;
    std::cout << machines_path_ << std::endl;
}

void Synchronizer::loadDefaultSettingsFromFile()
{
    auto const path = main_path_ == "/" ? "" + default_setting_path_ : main_path_ + default_setting_path_;
    // std::cout << "xxxxxxxxxxxxxx" << path << std::endl;
    // std::cout << default_setting_path_ << std::endl;
    // std::cout << machines_path_ << std::endl;
    // if ( main_path_ == "/" ) {
    //     main_path_ = "";
    // }
    std::ifstream stream( path );
    auto json = json::parse( stream );
    
    default_settings_ = SyncApp::DefaultSettingsInfo{ 
        .machineDirectory = json.at( "machine_directory" ),
        .isPreviouslySetings = json.at( "is_prev_settings" ),
        .syncTime = json.at( "sync_time" ),
        .machineSettingsFile = json.at( "machine_settings_file" ),
        .lastSyncDate = json.at( "last_sync_date" ) 
    };
}

