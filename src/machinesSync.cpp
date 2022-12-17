#include "machinesSync.hpp"
#include <iostream>

MachinesSync::MachinesSync( std::string const& main_path_ ) 
    : main_path_( main_path_ )
    , synchronizer_( std::make_unique< Synchronizer >( main_path_ ) ) 
    , machines_path_( synchronizer_->getMachinePath () )
{
}

void MachinesSync::run() {
    machinesInit();
}

void MachinesSync::machinesInit()
{
    for (auto const& dir_entry : fs::directory_iterator{ machines_path_ } ) 
    {
        machines_.push_back( std::make_unique< Machine > ( dir_entry.path() ) );
        //std::cout << dir_entry.path().filename() << '\n';
    }
}

