#include "synchronizer.hpp"
#include <iostream>
#include <algorithm>
#include <ranges>

Synchronizer::Synchronizer( std::string const& main_path, std::string const& default_setting_path ) 
    : main_path_( main_path )
    , default_setting_path_( default_setting_path )
{
    loadDefaultSettingsFromFile();
    setMachinesPath();
}

std::string Synchronizer::getMachinePath() const {
    return machines_path_;
}

DefaultSettingsInfo Synchronizer::getDefaultSettingsFromFile() const {
    return default_settings_;
}

void Synchronizer::setMachinesPath() {
    auto const machine_path = main_path_ + default_setting_path_;
    machines_path_ = main_path_ + default_settings_.machineDirectory;
}

void Synchronizer::loadDefaultSettingsFromFile()
{
    auto const path = main_path_ + default_setting_path_;
    std::ifstream stream( path );
    auto json = json::parse( stream );
    
    default_settings_ = DefaultSettingsInfo{ 
        .machineDirectory = json.at( "machine_directory" ),
        .isDeleteSync = json.at( "delete_sync" ),
        .syncTime = json.at( "sync_time" ),
        .machineSettingsFile = json.at( "machine_settings_file" ),
        .lastSyncDate = json.at( "last_sync_date" ) 
    };
}

void Synchronizer::saveDefaultSettingsToFile()
{
    
}

