#include "src/MachinesSync.hpp"
#include <filesystem>
#include <iostream>

namespace fs = std::filesystem;

int main() {
    std::string main_path = fs::current_path().parent_path();
    MachinesSync machineSync{ main_path };
    std::cout << "Before run\n";
    machineSync.run();

    std::cout << "EXIT\n";
    return 0;
}