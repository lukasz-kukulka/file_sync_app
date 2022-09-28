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

std::vector< std::unique_ptr< fs::directory_entry > > Machine::getAllMachineFiles()
{
    return std::move( files_pointers_ );
}

void Machine::setExistingFileInfo()
{
    for (auto const& file : fs::recursive_directory_iterator{ path_ } ) {
        if ( file.is_regular_file() ) {
            files_pointers_.push_back( std::make_unique< fs::directory_entry >( file) );
            exist_files_info_.emplace_back( file );
        }
    }
}

char* Machine::convertToLocalTime( std::time_t const& time ) {
    return std::asctime(std::localtime(&time));
}

void Machine::saveMachineFilesInfo( json const& json, fs::directory_entry dir_entry ) {
    std::string temp{};
    for ( auto const& file : new_files_info_ ) {

    }
}

void Machine::loadPreviouslyFilesInfo( json const& json, fs::directory_entry const& dir_entry ) {
    //.path().filename()
    auto const machine_settings = json.at( dir_entry.path().filename() );
    // for ( auto const& file_set : machine_settings ) {
    //     // auto file_info = FileInfo{ dir_entry };
    //     std::cout << "LOAD LOOP: " << file_set << "\n";
    //     // prev_files_info_.emplace_back( file_info );
    //     // prev_files_info_.back().setFileParam( file_set.mod_time, file_set.path, file_set.file_size );
    // }
    std::cout << machine_settings << std::endl;
    for (auto const& file : machine_settings ) {
        std::cout << file << std::endl;
    }

    prev_files_info_.back().setFileParam( machine_settings[ "mod_time" ], machine_settings[ "path" ], machine_settings[ "file_size" ] );

    //
    if ( machine_settings ) {
        // FileInfo file_info( dir_entry.path() );
        // prev_files_info_.emplace_back( file_info );
    }
    
    // prev_files_info_.back().setFileParam( machine_settings[ "mod_time" ], machine_settings[ "path" ], machine_settings[ "file_size" ] );

    // std::cout << "LOAD: " << machine_settings << "\n" << std::endl;
    // for ( auto const & test : prev_files_info_ ) {

    //     std::cout << test.getModTime() << "\n";

    // }
}

