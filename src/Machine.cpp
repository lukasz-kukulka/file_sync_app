#include "Machine.hpp"
#include "Time.hpp"
#include <iostream>
#include <chrono>
using namespace std::literals;

Machine::Machine( fs::path path ) 
    : path_( path )
    , machine_name_( path.filename() )
{
    path_.filename();
    setFilesPaths();
    //std::cout <<  path_.filename() << '\n';
}

std::vector< std::unique_ptr< fs::directory_entry > > Machine::getAllMachineFiles()
{
    // auto temp = std::vector< std::unique_ptr< fs::directory_entry > >(); 
    // return temp;
    return std::move( files_pointers_ );
}

void Machine::setFilesPaths()
{
    for (auto const& file : fs::recursive_directory_iterator{ path_ } ) {
        if ( file.is_regular_file() ) {
            files_pointers_.push_back( std::make_unique< fs::directory_entry >( file) );
            exist_files_info_.emplace_back( file );
        }
    }
    //test only 
    //new_files_info_ = exist_files_info_;
}

char* Machine::convertToLocalTime( std::time_t const& time ) {
    return std::asctime(std::localtime(&time));
}

void Machine::saveMachineFilesInfo( json const& json, fs::directory_entry dir_entry ) {
    std::string temp{};
    for ( auto const& file : new_files_info_ ) {

    }
}

void Machine::loadPreviouslyFilesInfo( json const& json, fs::directory_entry dir_entry ) {
    //.path().filename()
    auto const machine_settings = json.at( dir_entry.path().filename() );
    // for ( auto const& file_set : machine_settings ) {
    //     auto file_info = FileInfo{ dir_entry };
    //     prev_files_info_.emplace_back( file_info );
    //     prev_files_info_.back().setFileParam( file_set.mod_time, file_set.path, file_set.file_size );
    // }
    std::cout << "LOAD: " << machine_settings << "\n";
    for ( auto const & test : prev_files_info_ ) {

        std::cout << test.getModTime() << "\n";

    }
}

