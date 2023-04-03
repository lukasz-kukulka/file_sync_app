#include "src/MachinesSync.hpp"
#include <filesystem>
#include <iostream>

namespace fs = std::filesystem;

int main() {
    std::string main_path = fs::current_path().parent_path();
    MachinesSync machineSync{ main_path };
    machineSync.run();
    std::cout << "TEST";
    return 0;
}