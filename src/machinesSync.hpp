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
    json getJsonData( fs::path const& path );
    void machinesInit();
    void machinesFilesInit();
    void pathMachinesInit();
    void makeUniqueSyncFiles();
    fs::directory_entry* getNewestFile( fs::directory_entry* const file ) const;

    std::string main_path_{};
    std::string machines_path_{};
    std::vector< std::unique_ptr< Machine > > machines_;
    fs::path machine_setting_path_{};
    std::unique_ptr< Synchronizer > synchronizer_{};
    std::map< std::string, std::unique_ptr< fs::directory_entry > > unique_machine_files_{};
};