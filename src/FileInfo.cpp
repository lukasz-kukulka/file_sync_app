#include "FileInfo.hpp"
#include "Time.hpp"
#include <iostream>

FileInfo::FileInfo( fs::directory_entry const& file )
    : path_( file.path() )
    , file_size_( file.file_size() )
{
    setFileTime( file );
}

void FileInfo::setFileTime( fs::directory_entry file ) {
    mod_time_ = MainTime::getFileTime( file );
}

std::time_t FileInfo::getModTime() const {
    return mod_time_;
}

std::string FileInfo::getPath() const {
    return path_;
}
