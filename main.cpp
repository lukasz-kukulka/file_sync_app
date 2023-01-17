#include "src/synchronizer.hpp"
#include "src/machinesSync.hpp"
#include <filesystem>
#include <iostream>

//namespace fs = std::filesystem;

int main() {
    std::string main_path = fs::current_path().parent_path();
    Synchronizer synchronizer( main_path );
    MachinesSync machineSync( synchronizer.getMachinePath() );

    return 0;
}