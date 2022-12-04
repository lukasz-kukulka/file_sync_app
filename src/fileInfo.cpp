#include "fileInfo.hpp"
#include <iostream>
FileInfo::FileInfo( std::string path, uint64_t file_size, uint64_t mod_time )
    : path_( path )
    , file_size_( file_size )
    , mod_time_( mod_time )
{
}
