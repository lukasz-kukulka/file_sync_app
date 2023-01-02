#pragma once

#include <filesystem>
#include <memory>
#include <vector>
#include "machine.hpp"

namespace fs = std::filesystem;

class MachinesSync {
public:
    MachinesSync( std::string const& machines_path );

private:
    void machinesInit();
    std::string machines_path_{};
    std::vector< std::unique_ptr< Machine > > machines_;
};