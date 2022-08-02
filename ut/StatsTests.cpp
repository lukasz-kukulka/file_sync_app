#include <gtest/gtest.h>
#include "../src/FileInfo.hpp"
#include "../src/Stats.hpp"
#include <fstream>
#include <string>

namespace fs = std::filesystem;

std::string const kMachinePath = static_cast< std::string > ( fs::current_path().parent_path() ) + "/ut/MachinesTest";
fs::directory_entry const kDirEntry( kMachinePath );

void createTestFile( std::string const& file_name, std::string const& file_content ) {
  std::string const filepath = kMachinePath + file_name;
  std::ofstream file( filepath );
  if ( !file.is_open() ) {
    std::cerr << "ERROR!!! I Can't open " << filepath << " to write" << std::endl;
  }

  std::string data = file_content;
  std::copy(data.begin(), data.end(), std::ostream_iterator<char>(file));
  file << std::endl;
  file.close();
}

void generateTestMachine( int const machine_num, std::string const& file_name ) {
    for ( int i{}; i < machine_num; i++ ) {
        std::string machine_directory = "/M_test_" + std::to_string( i + 1 );
        fs::create_directory( kMachinePath + machine_directory );
        createTestFile( machine_directory + file_name, "test xxxx" );
    }
}

void deleteTestMachines() {
    for (auto const& file : fs::directory_iterator{ kMachinePath } ) {
        fs::remove_all( file );
    }
}

TEST( FileInfoCompareStats, IsGreater) {
    generateTestMachine( 4, "/test_file_1" );
    //std::cout << "______    TESTS  _____"<< kMachinePath + "/machine1_test/file2" << std::endl;
    FileInfo first( fs::directory_entry{ kMachinePath + "/machine1_test/file6" }, "file6", "machine1_test" );
    FileInfo second( fs::directory_entry{ kMachinePath + "/machine3_test/file6" }, "file6", "machine3_test" );
    //std::cout << "______    TESTS  _____"<< first.getAbsolutePath() << std::endl;
    // FileInfo file_info( dir_entry );
    auto const check_option = SyncApp::CompareOption::Greater;
    //EXPECT_EQ( check_option,  )
    // EXPECT_NE( 0, file_info.getFileSize() );
    // EXPECT_NE( 0, file_info.getModTime() );
    // EXPECT_NE( "", file_info.getPath() );
    deleteTestMachines();
}

TEST( FileInfoCompareStats, IsLess) {
    // fs::directory_entry const dir_entry( "D:/Programing/file_sync_app/ut/MachinesTest/machine1_test/file1.txt" );
    // FileInfo file_info( dir_entry );
    // EXPECT_NE( 0, file_info.getFileSize() );
    // EXPECT_NE( 0, file_info.getModTime() );
    // EXPECT_NE( "", file_info.getPath() );
}

TEST( FileInfoCompareStats, IsEqual) {
    // fs::directory_entry const dir_entry( "D:/Programing/file_sync_app/ut/MachinesTest/machine1_test/file1.txt" );
    // FileInfo file_info( dir_entry );
    // EXPECT_NE( 0, file_info.getFileSize() );
    // EXPECT_NE( 0, file_info.getModTime() );
    // EXPECT_NE( "", file_info.getPath() );
}

TEST( FileInfoCompareStats, IsDifferent) {
    // fs::directory_entry const dir_entry( "D:/Programing/file_sync_app/ut/MachinesTest/machine1_test/file1.txt" );
    // FileInfo file_info( dir_entry );
    // EXPECT_NE( 0, file_info.getFileSize() );
    // EXPECT_NE( 0, file_info.getModTime() );
    // EXPECT_NE( "", file_info.getPath() );
}