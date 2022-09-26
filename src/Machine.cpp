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
    auto const machine_settings = json.at( dir_entry.path().filename() );
    for (auto const& file : machine_settings ) {
        FileInfo file_info( file[ "mod_time" ], file[ "path" ], file[ "file_size" ] );
        prev_files_info_.emplace_back( file_info );
    }

    // for ( auto const & test : prev_files_info_ ) {

    //     std::cout << test.getModTime() << "\n";

    // }
}

