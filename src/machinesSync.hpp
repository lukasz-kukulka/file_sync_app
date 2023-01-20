#pragma once
#include "machine.hpp"
#include "synchronizer.hpp"
#include "nlohmann/json.hpp"

#include <filesystem>
#include <memory>
#include <vector>

namespace fs = std::filesystem;
using json = nlohmann::json;

class MachinesSync {
public:
    MachinesSync( std::string const& main_path_ );
    void run();
private:
    bool isFirstInit();
    void machinesInit();
    void machinesFilesInit();
    std::string main_path_{};
    std::string machines_path_{};
    std::vector< std::unique_ptr< Machine > > machines_;
    fs::path machine_setting_path_{};
    std::unique_ptr< Synchronizer > synchronizer_{};
};