#include "Machine.hpp"
#include "Time.hpp"
#include <iostream>
#include <chrono>
using namespace std::literals;

Machine::Machine( fs::path const& path ) 
    : path_( path )
    , machine_name_( path.filename() )
{
    path_.filename();
    setExistingFileInfo();
}

// std::vector< std::unique_ptr< fs::directory_entry > > Machine::getAllMachineFiles() {
//     return std::move( files_pointers_ );
// }

void Machine::setExistingFileInfo() {
    for (auto const& file : fs::recursive_directory_iterator{ path_ } ) {
        if ( file.is_regular_file() ) {
            //files_pointers_.push_back( std::make_unique< fs::directory_entry >( file ) );
            // std::cout << file << std::endl;
            // std::cout << path_ << std::endl;
            // std::cout << path_.filename() << std::endl;
            
            auto const file_path = getPathToFile( file, path_);
            exist_files_info_.emplace_back( file, file_path, path_.filename() );
        }
    }
}

std::string Machine::getPathToFile(fs::directory_entry const& file, fs::path const& path) {
    auto const full_path = static_cast< std::string >( file.path() );
    auto const substring_index = full_path.find( path );
    auto const machine_full_path = static_cast< std::string >( path );

    if ( substring_index != std::string::npos ) {
        return full_path.substr( machine_full_path.length(), full_path.length() - machine_full_path.length());
    }
    return "";
}

void Machine::saveMachineFilesInfo( json const& json, fs::directory_entry dir_entry ) {
    //TO DO
    std::string temp{};
    //std::cout << json << std::endl;
    for ( auto const& file : new_files_info_ ) {
        
    }
}

std::vector< FileInfo >& Machine::getFileInfo() {
    return exist_files_info_;
}

void Machine::loadPreviouslyFilesInfo( json const& json, std::string const& machine_name ) {
    if ( auto const machine_settings = json.find( machine_name ); machine_settings != json.end() ) {
        for (auto const& file : machine_settings.value() ) {
            // FileInfo file_info( file[ "mod_time" ], file[ "path" ], file[ "file_size" ] );
            // prev_files_info_.emplace_back( file_info );
        }
    }
}

