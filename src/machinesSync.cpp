#include "machinesSync.hpp"
#include <iostream>

namespace {
    const std::string kSettingsDirectory = "/settings";
    const std::string kDefaultSettingsFileName = "/machines_default_settings.json";
}

MachinesSync::MachinesSync( std::string const& main_path_ ) 
    : main_path_( main_path_ )
    , synchronizer_( std::make_unique< Synchronizer >( main_path_, kSettingsDirectory + kDefaultSettingsFileName ) ) 
    , machines_path_( synchronizer_->getMachinePath () )
{
}

void MachinesSync::run() {
    machinesInit();
}

bool MachinesSync::isFirstInit() {
    auto const path = main_path_ + kSettingsDirectory;
    std::ifstream stream( path );
    auto json = json::parse( stream );
    if ( json.empty() ) {
        return true;
    }
    return false;
}

void MachinesSync::machinesInit()
{
    if ( isFirstInit() ) {
        std::cout << 
    }
    for (auto const& dir_entry : fs::directory_iterator{ machines_path_ } ) 
    {
        machines_.push_back( std::make_unique< Machine > ( dir_entry.path() ) );
        //std::cout << dir_entry.path().filename() << '\n';
    }
}

