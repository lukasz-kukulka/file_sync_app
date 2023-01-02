#pragma once
#include <string>
#include <filesystem>

namespace fs = std::filesystem;

class Machine {
public:
    Machine( std::string name );

private:
    std::string name_{};
};