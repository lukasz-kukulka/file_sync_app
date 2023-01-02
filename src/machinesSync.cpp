#include "machinesSync.hpp"
#include <iostream>

MachinesSync::MachinesSync( std::string const& machines_path ) 
    : machines_path_( machines_path )
{
    machinesInit();
}

void MachinesSync::machinesInit()
{
    for (auto const& dir_entry : std::filesystem::directory_iterator{ machines_path_ } ) 
    {
        machines_.push_back( std::make_unique< Machine > ( dir_entry.path().filename() ) );
        //std::cout << dir_entry.path().filename() << '\n';
    }
}