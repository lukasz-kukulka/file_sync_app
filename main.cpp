#include "src/synchronizer.hpp"
#include <filesystem>
#include <iostream>

//namespace fs = std::filesystem;

int main() {
    fs::path main_path = fs::current_path().parent_path();
    Synchronizer synchronizer( main_path );
    return 0;
}