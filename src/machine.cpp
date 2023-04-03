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
    std::cout <<  path_.filename() << '\n';
}

std::vector< std::unique_ptr< fs::directory_entry > > Machine::getAllMachileFiles()
{
    // auto temp = std::vector< std::unique_ptr< fs::directory_entry > >(); 
    // return temp;
    return files_pointers_;
}

void Machine::setFilesPaths()
{
    for (auto const& file : fs::recursive_directory_iterator{ path_ } ) {
        if ( file.is_regular_file() ) {
            files_pointers_.push_back( std::make_unique< fs::directory_entry >( file) );
            //exist_files_info_.emplace_back( file.path(), file.file_size(), MainTime::getFileTime( file ) );
        }
    }
    //test only 
    //new_files_info_ = exist_files_info_;
}

char* Machine::convertToLocalTime( std::time_t const& time ) {
    return std::asctime(std::localtime(&time));
}

void Machine::saveMachineFilesInfo( json const& json ) {
    std::string temp{};
    for ( auto const& file : new_files_info_ ) {
        temp += file.getPath(); 
    }
    //json.parse( new_files_info_ );
}

void Machine::loadPreviouslyFilesInfo( json const& json ) {
    for ( auto const& file : json.at( "machine_name_" ) ) {
        //prev_files_info_.emplace_back( file.at( "path" ), file.at( "file_size" ), file.at( "mod_time" ) );
    }
}
