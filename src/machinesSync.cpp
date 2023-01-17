#include "machinesSync.hpp"
#include <iostream>

MachinesSync::MachinesSync( std::string const& machines_path ) 
    : machines_path_( machines_path )
{
    machinesInit();
}

void MachinesSync::machinesInit()
{
    for (auto const& dir_entry : fs::directory_iterator{ machines_path_ } ) 
    {
        fs::path x = dir_entry.path();
        machines_.push_back( std::make_unique< Machine > ( dir_entry.path() ) );
        //std::cout << dir_entry.path().filename() << '\n';
    }
}