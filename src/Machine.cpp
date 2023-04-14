#include "Machine.hpp"
#include "Time.hpp"
#include <iostream>
#include <chrono>
using namespace std::literals;

Machine::Machine( fs::path path ) 
    : path_( path )
    , machine_name_( path.filename() )
{
    path_.filename();
    setExistingFileInfo();
}

std::vector< std::unique_ptr< fs::directory_entry > > Machine::getAllMachineFiles() {
    return std::move( files_pointers_ );
}

void Machine::setExistingFileInfo() {
    for (auto const& file : fs::recursive_directory_iterator{ path_ } ) {
        if ( file.is_regular_file() ) {
            files_pointers_.push_back( std::make_unique< fs::directory_entry >( file) );
            // std::cout << file << std::endl;
            // std::cout << path_ << std::endl;
            // std::cout << path_.filename() << std::endl;
            exist_files_info_.emplace_back( file, path_, path_.filename() );
        }
    }
}

void Machine::saveMachineFilesInfo( json const& json, fs::directory_entry dir_entry ) {
    //TO DO
    std::string temp{};
    //std::cout << json << std::endl;
    for ( auto const& file : new_files_info_ ) {
        
    }
}

void Machine::loadPreviouslyFilesInfo( json const& json, std::string const& machine_name ) {
    if ( auto const machine_settings = json.find( machine_name ); machine_settings != json.end() ) {
        for (auto const& file : machine_settings.value() ) {
            // FileInfo file_info( file[ "mod_time" ], file[ "path" ], file[ "file_size" ] );
            // prev_files_info_.emplace_back( file_info );
        }
    }
}

