#include "fileInfo.hpp"
#include <iostream>
FileInfo::FileInfo( fs::directory_entry const& file )
    : name_( file.path().filename() )
    , mod_time_( getFileTime( file ))
    , file_size_( file.file_size() )
{
}

std::time_t FileInfo::getFileTime( fs::directory_entry file ) {
    auto file_time = file.last_write_time();
    auto f_sys_time = std::chrono::file_clock::to_sys( file_time );
    std::time_t time = std::chrono::system_clock::to_time_t( f_sys_time );
    return time;
}