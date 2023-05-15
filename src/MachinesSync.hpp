#pragma once
#include "Machine.hpp"
#include "Command.hpp"
#include "Synchronizer.hpp"
#include "nlohmann/json.hpp"

#include <filesystem>
#include <memory>
#include <vector>
#include <map>
#include <set>

namespace fs = std::filesystem;
using json = nlohmann::json;

class MachinesSync : public Command {
public:
    MachinesSync( std::string const& main_path_ );
    ~MachinesSync() = default;
    void operator()(std::vector< FileInfo >const& file_info ) override;
    
private:
    void run();
    void prepareForMachineSync();
    json getJsonData( fs::path const& path );
    void machinesInit();
    void machinesFilesInit();
    void pathMachinesInit();
    void makeUniqueSyncFiles();
    void compareAndAddFileInfo( FileInfo& file_info );
    void changeFilesIfIsOlder();
    void replaceSingleFile( FileInfo& old_file, FileInfo& new_file );
    void addNewFilesIfDontExist( std::set< std::string >const& existing_file_paths, std::string const& path_to_copy );
    

    std::string main_path_{};
    std::string machines_path_{};
    std::vector< std::unique_ptr< Machine > > machines_;
    fs::path machine_setting_path_{};
    std::unique_ptr< Synchronizer > synchronizer_{};
    std::map< std::string, FileInfo > unique_machine_files_info_{};
};