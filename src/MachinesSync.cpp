#include "MachinesSync.hpp"
#include "Time.hpp"
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
    machines_path_ = synchronizer_->getMachinePath();
    std::cout << machines_path_ << std::endl;
    //auto dir_entry = fs::directory_iterator{ machines_path_ };    
}

void MachinesSync::run() {
    prepareForMachineSync();
    machinesInit();
    makeUniqueSyncFiles();
    changeFileIfIsOlder();
}

void MachinesSync::prepareForMachineSync() {
    unique_machine_files_info_.clear();
    machines_.clear();
}

json MachinesSync::getJsonData( fs::path const& path ) {
    std::ifstream stream( path );
    return json::parse( stream );
}

void MachinesSync::machinesInit() {
    // zrobic to na kilku watkach  
    
    fs::path const machine_settings_file_path = main_path_ + kSettingsDirectory + synchronizer_->getDefaultSettingsFromFile().machineSettingsFile;
    auto const is_prev_settings = synchronizer_->getDefaultSettingsFromFile().isPreviouslySetings;
    auto const directories = fs::directory_iterator{ machines_path_ };
    for (auto const& dir_entry : directories ) {
        machines_.push_back( std::make_unique< Machine > ( dir_entry.path() ) );
        if ( is_prev_settings ) {
            machines_.back()->loadPreviouslyFilesInfo( getJsonData( machine_settings_file_path ), dir_entry.path().filename() );
        }
    }
}

void MachinesSync::makeUniqueSyncFiles() {
    for ( auto const & machine : machines_ ) {
        for ( auto const & file : machine->getFileInfo() ) {
            if ( auto const exist_file = unique_machine_files_info_.find( file.getPath() ) ) {
                auto const new_file_info = SyncApp::compareFilesInfo( file, exist_file );
                unique_machine_files_info_.insert_or_assign( new_file_info.getPath(), new_file_info.getMachineName() )
            } else {
                unique_machine_files_info_.insert( file.getPath(), file.getMachineName() )
            }
        }
    }
}

void MachinesSync::changeFileIfIsOlder() {
    // auto file_if_match = [ this ]( auto element ){ 
    //     return std::ranges::find( unique_machine_files_, element ); 
    // }; 

    // for ( auto const & file : unique_machine_files_ ) {
    //     for( auto const & machine : machines_ ) {
           
    //     }
    // }
}

