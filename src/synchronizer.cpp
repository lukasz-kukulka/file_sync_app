#include "synchronizer.hpp"
#include <iostream>
#include <algorithm>
#include <ranges>

namespace {
    const std::string kSettingsFiles = "/settings";
    const std::string kDefaultSettings = "/machines_default_settings.json";
}

Synchronizer::Synchronizer( std::string  main_path ) 
    : main_path_( main_path )
{
    setMachinesPath();
}

std::string Synchronizer::getMachinePath() const {
    return machines_path_;
}

void Synchronizer::setMachinesPath() {
    auto const machine_path = main_path_ + kSettingsFiles + kDefaultSettings;
    machines_path_ = main_path_ + getParsedSettings( machine_path, "machine_directory"  );
}

std::string Synchronizer::getParsedSettings( std::string const& path, std::string const& settings_name ) {
    std::ifstream stream( path );
    auto json = json::parse( stream );
    return json.at( settings_name );
}
