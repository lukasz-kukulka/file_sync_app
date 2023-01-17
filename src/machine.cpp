#include "machine.hpp"

#include <iostream>
Machine::Machine( fs::path path ) 
    :path_( path )
{
    setFilesPaths();
}

void Machine::setFilesPaths()
{
    
    auto get_time = [](fs::file_time_type const& ftime) {
        std::time_t time = std::chrono::system_clock::to_time_t( std::chrono::file_clock::to_sys(ftime) );
        return time;//std::asctime(std::localtime(&time));
         };
    for (auto const& file : fs::recursive_directory_iterator{ path_ } ) {
        std::cout << file.path()  << '\n';
    }
    
    //std::vector< fs::path > files_path_{};
} 