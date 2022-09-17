#include "src/MachinesSync.hpp"
#include "src/Menu.hpp"
#include <filesystem>
#include <iostream>

namespace fs = std::filesystem;

int main() {
    std::string main_path = fs::current_path().parent_path();
    MachinesSync machineSync{ main_path };
    std::cout << "Before run\n";
    Menu menu;
    menu.runMenu();
    //machineSync.run();
    
    std::cout << "EXIT\n";
    return 0;
}