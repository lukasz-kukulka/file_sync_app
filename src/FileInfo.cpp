#include "FileInfo.hpp"
#include "Time.hpp"
#include <iostream>

FileInfo::FileInfo( fs::directory_entry const& file, std::string const& path, std::string const& machine_name )
    : absolute_path_( file.path() )
    , path_( path )
    , machine_name_( machine_name )
    , file_size_( file.file_size() )
{
    setFileTime( file );
    std::cout << "AP: " << absolute_path_ << ", P: " << path_ << ", MN: " << machine_name << ", FS: " << file_size_ << ", FT: " << mod_time_ << std::endl;
}

// FileInfo::FileInfo( uint64_t const& mod_time, std::string const& path, uint64_t const& file_size )
//     : path_( path )
//     , mod_time_( mod_time )
//     , file_size_ ( file_size )
// {
//     // if( not path.empty() ) {
//     //     fs::directory_entry const dir_entry( path );
//     //     setFileTime( file );
//     // }
    

// }

void FileInfo::setFileTime( fs::directory_entry file ) {
    mod_time_ = MainTime::getFileTime( file );
}

std::time_t FileInfo::getModTime() const {
    return mod_time_;
}

std::string FileInfo::getAbsolutePath() const {
    return absolute_path_;
}

uint64_t FileInfo::getFileSize() const {
    return file_size_;
}

std::string FileInfo::getMachineName() const {
    return machine_name_;
}

std::string FileInfo::getPath() const {
    return path_;
}
