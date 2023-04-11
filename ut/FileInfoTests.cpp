#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../src/FileInfo.hpp"

namespace fs = std::filesystem;

TEST(FileInfoTest, CreateObjectFirstConstructor) {
    fs::directory_entry const dir_entry( "D:/Programing/file_sync_app/ut/MachinesTest/machine1_test/file1.txt" );
    FileInfo file_info( dir_entry );
    EXPECT_NE( 0, file_info.getFileSize() );
    EXPECT_NE( 0, file_info.getModTime() );
    EXPECT_NE( "", file_info.getPath() );
}

TEST(FileInfoTest, CreateObjectSecondConstructor) {
    std::string const path = "D:/Programing/file_sync_app/ut/MachinesTest/machine1_test/file1.txt";
    uint64_t const mod_time = 22222;
    uint64_t const file_size = 2000;
    FileInfo file_info( mod_time, path, file_size);
    EXPECT_EQ( file_size, file_info.getFileSize() );
    EXPECT_EQ( mod_time, file_info.getModTime() );
    EXPECT_EQ( path, file_info.getPath() );
}