#include "Machine.hpp"
#include "Time.hpp"
#include <iostream>
#include <chrono>
using namespace std::literals;

Machine::Machine( fs::path const& path ) 
    : path_( path )
    , machine_name_( path.filename().string() )
{
    //path_.filename();
    setExistingFileInfo();
}

void Machine::setExistingFileInfo() {
    for (auto const& file : fs::recursive_directory_iterator{ path_ } ) {
        if ( file.is_regular_file() ) {
            auto const file_path = getPathToFile( file, path_);
            exist_files_info_.insert( { file_path, FileInfo( file, file_path, path_.filename().string() ) } );
        }
    }
}

std::string Machine::getPathToFile(fs::directory_entry const& file, fs::path const& path) {
    auto const full_path = static_cast< std::string >( file.path().string() );
    auto const substring_index = full_path.find( path.string() );
    auto const machine_full_path = static_cast< std::string >( path.string() );

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

std::string Machine::getMachineName() const {
    return machine_name_;
}

void Machine::addNewFileInfo(FileInfo const& file_info) {
    exist_files_info_.insert( { file_info.getPath(), file_info } );
}

std::string Machine::getMachinePatch() const {
    return path_.string();
}

std::map< std::string, FileInfo >& Machine::getFileInfo() {
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

