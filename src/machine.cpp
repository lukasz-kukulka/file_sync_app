#include "machine.hpp"
#include <iostream>
#include <chrono>
using namespace std::literals;

Machine::Machine( fs::path path ) 
    :path_( path )
{
    setFilesPaths();
}

void Machine::setFilesPaths()
{
    
    auto get_time = [](fs::file_time_type const& ftime) {
        std::time_t time = std::chrono::system_clock::to_time_t( std::chrono::file_clock::to_sys(ftime) );
        return time;
        //return std::asctime(std::localtime(&time));
         };
    for (auto const& file : fs::recursive_directory_iterator{ path_ } ) {
        auto xx = std::chrono::system_clock::now();
        std::chrono::system_clock::to_time_t( xx );
        std::cout <<  std::chrono::system_clock::to_time_t( xx ) << "  -   " << get_time( file.last_write_time() ) << "  -   \n";
    }
    
    //std::vector< fs::path > files_path_{};
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

void Machine::saveMachineInfo() {
    
}

void Machine::loadMachineInfo() {
    
}
