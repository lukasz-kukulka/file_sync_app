#include "machinesSync.hpp"
#include <iostream>
#include <ranges>
#include <algorithm>

namespace {
    const std::string kSettingsDirectory = "/settings";
    const std::string kDefaultSettingsFileName = "/machines_default_settings.json";
}

MachinesSync::MachinesSync( std::string const& main_path_ ) 
    : main_path_( main_path_ )
    , synchronizer_( std::make_unique< Synchronizer >( main_path_, kSettingsDirectory + kDefaultSettingsFileName ) )  
{
    machines_path_ = synchronizer_->getMachinePath ();
}

void MachinesSync::run() {
    machinesInit();
}

json MachinesSync::getJsonData( fs::path const& path ) {
    std::ifstream stream( path );
    return json::parse( stream );
}

void MachinesSync::machinesInit() { 
    // zrobic to na kilku watkach  
    auto const path = main_path_ + kSettingsDirectory + synchronizer_->getDefaultSettingsFromFile().machineSettingsFile;
    //auto const json = getJsonData( path );
    auto const init_file_exist =  synchronizer_->getDefaultSettingsFromFile().lastSyncDate;

    for (auto const& dir_entry : fs::directory_iterator{ machines_path_ } ) {
        machines_.push_back( std::make_unique< Machine > ( dir_entry.path() ) );
        if ( init_file_exist ) {
            machines_.back()->loadPreviouslyFilesInfo( getJsonData( dir_entry.path() ) );
        }
    }

    for (auto const& dir_entry : fs::directory_iterator{ machines_path_ } ) {
        machines_.push_back( std::make_unique< Machine > ( dir_entry.path() ) );
            machines_.back()->saveMachineFilesInfo( getJsonData( dir_entry.path() ) );
        
    }
}

void MachinesSync::makeUniqueSyncFiles()
{
    for ( auto const & machine : machines_ )
    {
        for ( auto const & file : machine->getAllMachileFiles() )
        if ( unique_machine_files_.contains( file->path().filename() ) )
        {
            if( file-)
        }
    }
    unique_machine_files_
}

