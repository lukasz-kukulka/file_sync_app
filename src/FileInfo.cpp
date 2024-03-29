#include "FileInfo.hpp"
#include "Time.hpp"
#include <iostream>

FileInfo::FileInfo( fs::directory_entry const& file, std::string const& path, std::string const& machine_name )
{
    if ( not file.is_regular_file() ) {
        throw std::invalid_argument( "Directory entry is not regular file" );
    } 
    absolute_path_ = file.path().string();
    path_ = path;
    machine_name_ = machine_name;
    file_size_ = file.file_size();
    setFileTime( file );
    //setPtrForMachineFileInfo( this );
    //std::cout << "AP: " << absolute_path_ << ", P: " << path_ << ", MN: " << machine_name << ", FS: " << file_size_ << ", FT: " << mod_time_ << std::endl;
}

FileInfo::FileInfo()
{}


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
    mod_time_ = MainTime::getFileTimeHighPrecision( file );
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

void FileInfo::setIsFileToReplace( bool is_to_replace ) {
    is_file_to_replace_ = is_to_replace;
}

bool FileInfo::getIsFileToReplace() const {
    return is_file_to_replace_;
}

void FileInfo::replaceAllFileInfo(FileInfo const& new_info) {
    machine_name_ = new_info.getMachineName();
    absolute_path_ = new_info.getAbsolutePath();
    path_ = new_info.getPath();
    mod_time_ = new_info.getModTime();
    file_size_ = new_info.getFileSize();
    setIsFileToReplace( new_info.getIsFileToReplace() );
}

// void FileInfo::setPtrForMachineFileInfo(FileInfo* ptr) {
//     ptr_to_file_info_in_machine_ = ptr;
// }

// FileInfo* FileInfo::getPtrForMachineFileInfo() const {
//     return ptr_to_file_info_in_machine_;
// }