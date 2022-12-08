#include "machine.hpp"
#include <iostream>
#include <chrono>
using namespace std::literals;

Machine::Machine( fs::path path ) 
    : path_( path )
    , machine_name_( path.filename() )
{
    path_.filename();
    setFilesPaths();
    std::cout <<  path_.filename() << '\n';
}

void Machine::setFilesPaths()
{
    for (auto const& file : fs::recursive_directory_iterator{ path_ } ) {
        if ( file.is_regular_file() ) {
            std::cout <<  file.path() << ":  " << getFileTime( file ) << '\n';
            exist_files_info_.emplace_back( file, getFileTime( file ) );
        }
    }
}

std::time_t Machine::getFileTime( fs::directory_entry file ) {
    auto file_time = file.last_write_time();
    auto f_sys_time = std::chrono::file_clock::to_sys( file_time );
    std::time_t time = std::chrono::system_clock::to_time_t( f_sys_time );
    return time;
}

char* Machine::convertToLocalTime( std::time_t const& time ) {
    return std::asctime(std::localtime(&time));
}

void Machine::saveMachineFilesInfo() {
    
}

void Machine::loadMachineFilesInfo( json const& json ) {
    
}
