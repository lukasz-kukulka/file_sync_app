#pragma once
#include "Machine.hpp"
#include "Synchronizer.hpp"
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
    void prepareForMachineSync();
    json getJsonData( fs::path const& path );
    void machinesInit();
    void machinesFilesInit();
    void pathMachinesInit();
    void makeUniqueSyncFiles();
    void compareAndAddFileInfo( FileInfo const& file_info );
    void changeFileIfIsOlder();
    

    std::string main_path_{};
    std::string machines_path_{};
    std::vector< std::unique_ptr< Machine > > machines_;
    fs::path machine_setting_path_{};
    std::unique_ptr< Synchronizer > synchronizer_{};
    std::map< std::string, FileInfo > unique_machine_files_info_{};
};