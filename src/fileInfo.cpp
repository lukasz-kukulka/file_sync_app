#include "fileInfo.hpp"
#include <iostream>
FileInfo::FileInfo( fs::directory_entry const& file )
    : path_( file.path() )
    , file_size_( file.file_size() )
{
    setFileTime( file );
}

void FileInfo::setFileTime( fs::directory_entry file ) {
    auto file_time = file.last_write_time();
    auto f_sys_time = std::chrono::file_clock::to_sys( file_time );
    std::time_t time = std::chrono::system_clock::to_time_t( f_sys_time );
    mod_time_ = time;
}

std::time_t FileInfo::getModTime() const {
    return mod_time_;
}