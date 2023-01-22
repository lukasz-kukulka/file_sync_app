#include "fileInfo.hpp"
#include <iostream>
FileInfo::FileInfo( fs::directory_entry directory_entry, std::time_t time )
    : path_( directory_entry.path() )
    , file_size_( directory_entry.file_size() )
    , mod_time_( time )
{
}
