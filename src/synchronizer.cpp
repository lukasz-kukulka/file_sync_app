#include "synchronizer.hpp"
#include <iostream>
#include <algorithm>
#include <ranges>

namespace {
    const std::string kSettingsFiles = "/settings";
    const std::string kDefaultSettings = "/machines_default_settings.json";
}

Synchronizer::Synchronizer( fs::path main_path ) 
    : main_path_( main_path )
{
    setMachinesPath();
}

void Synchronizer::setMachinesPath() {
    auto const machine_path = static_cast < std::string > ( main_path_ ) + kSettingsFiles + kDefaultSettings;
    machines_path_ = getParsedSettings( machine_path, "machine_directory"  );
}

std::string Synchronizer::getParsedSettings( std::string const& path, std::string const& settings_name ) {
    std::ifstream stream( path );
    auto json = json::parse( stream );
    std::cout << json.at( settings_name ) << '\n';
    return json.at( settings_name );
}
