#include "synchronizer.hpp"
#include <iostream>
#include <algorithm>
#include <ranges>

namespace {
    const std::string kDefaultSettings = "/settings/machines_default_settings.json";
}

Synchronizer::Synchronizer( std::string  main_path ) 
    : main_path_( main_path )
{
    setDefaultSettingsFromFile();
    setMachinesPath();
}

std::string Synchronizer::getMachinePath() const {
    return machines_path_;
}

void Synchronizer::setMachinesPath() {
    auto const machine_path = main_path_ + kDefaultSettings;
    machines_path_ = main_path_ + default_settings_.machineDirectory;
}

void Synchronizer::setDefaultSettingsFromFile()
{
    auto const path = main_path_ + kDefaultSettings;
    std::ifstream stream( path );
    auto json = json::parse( stream );
    
    default_settings_ = DefaultSettingsInfo{ .machineDirectory = json.at( "machine_directory" ),
    .isDeleteSync = json.at( "delete_sync" ),
    .syncTime = json.at( "sync_time" ),
    .machineSettingsFile = json.at( "machine_settings_file" ) };
}

