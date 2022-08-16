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
    for ( auto const & machine : machines_ )
    {
        //std::cout << "Machine" << std::endl;
        for ( auto const & file : machine->getFileInfo() )
        {
            //std::cout << "FILE" << std::endl;
            unique_machine_files_info_;
        }
    }
}

std::pair< std::string, std::unique_ptr < fs::directory_entry > > MachinesSync::getNewestFile( fs::directory_entry* const file ) const {
    auto const find = unique_machine_files_.find( file->path().filename() );
    auto new_record = std::make_pair< std::string, std::unique_ptr < fs::directory_entry > >( file->path().filename(), std::make_unique < fs::directory_entry >( *file ) );
    if ( find != unique_machine_files_.end() ) {
        if ( file->path().filename() == find->second->path().filename() ) {
            if ( MainTime::getFileTime( *file ) > MainTime::getFileTime( *find->second ) ) {
                new_record.second = std::make_unique < fs::directory_entry >( *file );
            } else {
                new_record.second = std::make_unique < fs::directory_entry >( *find->second );
            }
        }
    }
    return new_record;
}

void MachinesSync::changeFileIfIsOlder() {
    auto file_if_match = [ this ]( auto element ){ 
        return std::ranges::find( unique_machine_files_, element ); 
    }; 

    for ( auto const & file : unique_machine_files_ ) {
        for( auto const & machine : machines_ ) {
           
        }
    }
}

