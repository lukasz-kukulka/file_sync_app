#pragma once

#include "fileInfo.hpp"

#include <chrono>
#include <filesystem>
#include <string>
#include <vector>

namespace fs = std::filesystem;

class Machine {
public:
    Machine( fs::path path );
    
private:
    void setFilesPaths();
    void saveMachineInfo();
    void loadMachineInfo();
    std::vector< FileInfo > files_status_{};
    fs::path path_{};
};