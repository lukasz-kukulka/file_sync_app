#include "fileInfo.hpp"
#include <iostream>
FileInfo::FileInfo( fs::directory_entry directory_entry ) 
    :directory_entry_( directory_entry )
{
    system_time_ = setSystemTime( fs::last_write_time( directory_entry_ ) );
}

bool FileInfo::operator==( const FileInfo& lhs ) const
{
    //TODO
    
    return true;
}

std::time_t FileInfo::setSystemTime( fs::file_time_type const& ftime )
{
    return std::chrono::system_clock::to_time_t( std::chrono::file_clock::to_sys(ftime) );
}

