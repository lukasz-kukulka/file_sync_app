#include "MachinesSync.hpp"

#include "Stats.hpp"
#include "Time.hpp"
#include <iostream>
#include <iterator>
#include <ranges>
#include <algorithm>

namespace {
    const std::string kSettingsDirectory = "/settings";
    const std::string kDefaultSettingsFileName = "/machines_default_settings.json";
}

MachinesSync::MachinesSync( std::string const& main_path ) 
    : main_path_( main_path )
    , synchronizer_( std::make_unique< Synchronizer >( main_path, kSettingsDirectory + kDefaultSettingsFileName ) )  
{
    machines_path_ = synchronizer_->getMachinePath();
}

void MachinesSync::operator()(std::vector< FileInfo >const& file_info) {
    run();
}

void MachinesSync::run() {
    prepareForMachineSync();
    machinesInit();
    makeUniqueSyncFiles();
    changeFilesIfIsOlder();
}

void MachinesSync::prepareForMachineSync() {
    unique_machine_files_info_.clear();
    machines_.clear();
}

json MachinesSync::getJsonData( fs::path const& path ) {
    std::ifstream stream( path );
    return json::parse( stream );
}

void MachinesSync::machinesInit() {
    auto const is_prev_settings = synchronizer_->getDefaultSettingsFromFile().isPreviouslySetings;
    auto const directories = fs::directory_iterator{ machines_path_ };
    for (auto const& dir_entry : directories ) {
        machines_.push_back( std::make_unique< Machine > ( dir_entry.path() ) );
        if ( is_prev_settings ) {
            //machines_.back()->loadPreviouslyFilesInfo( getJsonData( machine_settings_file_path ), dir_entry.path().filename() );
        }
    }
}

void MachinesSync::makeUniqueSyncFiles() {
    for ( auto & machine : machines_ ) {
        for ( auto & file : machine->getFileInfo() ) {
            compareAndAddFileInfo( file.second, machine.get() );
        }
    }
    for ( auto & machine : machines_ ) {
        for ( auto & file : machine->getFileInfo() ) {
            std::cout << "PATH = " << file.second.getAbsolutePath() << "   |    " << std::boolalpha << file.second.getIsFileToReplace() << std::endl;
        }
        std::cout << std::endl;
    }
    // for ( auto const & fil : unique_machine_files_info_ ) {
    //     std::cout << fil.second.getAbsolutePath() << std::endl;
    // }
}

void MachinesSync::compareAndAddFileInfo( FileInfo& file, Machine* machine ) {
    auto exist_file = unique_machine_files_info_.find( file.getPath() );
    if ( exist_file != unique_machine_files_info_.end() ) {
        auto new_file_info = SyncApp::compareFilesInfo( &file, &exist_file->second );
        if ( new_file_info && ( exist_file->second.getModTime() != new_file_info->getModTime() ) ) {
            unique_machine_files_info_.insert_or_assign( new_file_info->getPath(), *new_file_info );
            findAndChangeVariableFileIsToChange( exist_file->second.getMachineName(), exist_file->second.getPath(), true );
            findAndChangeVariableFileIsToChange( new_file_info->getMachineName(), exist_file->second.getPath(), false );
        }
    } else {
        unique_machine_files_info_.insert( { file.getPath(), file } );
        
    }
}

void MachinesSync::changeFilesIfIsOlder() {
    for ( auto const & unique_file : unique_machine_files_info_ ) {
        for ( auto & machine : machines_ ) {
            auto const file_info = machine->getFileInfo().find( unique_file.first );
            if( file_info == machine->getFileInfo().end() ) {
                addNewFilesIfDontExist( unique_file.second.getAbsolutePath(), 
                                        machine->getMachinePatch() + unique_file.second.getPath() );
            } else if ( file_info != machine->getFileInfo().end() && file_info->second.getIsFileToReplace() ) {
                replaceSingleFile( file_info->second, unique_file.second );
            }
        }
    }
    // for ( auto & machine : machines_ ) {
    //     for ( auto const & info : unique_machine_files_info_ ) { 
    //         auto const exist_file = machine->getFileInfo().find( info.first );
    //     }
    //     std::cout << std::endl; 
    // }
}

void MachinesSync::replaceSingleFile(FileInfo const& old_file, FileInfo const& new_file) {
    std::filesystem::path old_file_path( old_file.getAbsolutePath() );
    std::filesystem::path new_file_path( new_file.getAbsolutePath() );
    std::cout << new_file.getAbsolutePath() << " <--- old x|x new ---> " << old_file.getAbsolutePath() << std::endl;
    std::filesystem::copy_file( old_file_path, new_file_path, std::filesystem::copy_options::overwrite_existing );
}

void MachinesSync::addNewFilesIfDontExist( std::string const& existing_file_paths, std::string const& path_to_copy ) {
    //for( auto const& path : existing_file_paths ) {
        std::filesystem::path existing_file( existing_file_paths );
        std::filesystem::path new_path( path_to_copy );
        std::cout << existing_file << " <--- old y|y new ---> " << new_path << std::endl;
        std::filesystem::copy_file( path_to_copy, existing_file );
    //}
}

void MachinesSync::findAndChangeVariableFileIsToChange(std::string const& machine_name, std::string const& file_patch, bool is_to_change ) {
    for ( auto & machine : machines_ ) {
        if( machine->getMachineName() == machine_name ) {
            for ( auto & file : machine->getFileInfo() ) {
                if ( file.second.getPath() == file_patch ) {
                    file.second.setIsFileToReplace( is_to_change );
                }
            }
        }
        
    }
}
