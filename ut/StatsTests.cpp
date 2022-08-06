#include <gtest/gtest.h>
#include "../src/FileInfo.hpp"
#include "../src/Stats.hpp"
#include <ofstream>
#include <string>

namespace fs = std::filesystem;

std::string const kMachinePath = static_cast< std::string > ( fs::current_path().parent_path() ) + "/ut/MachinesTest";
fs::directory_entry const kDirEntry( kMachinePath );

void createTestFile( std::string file_name, std::string file_content ) {
  fs::path filepath = kMachinePath + file_name;
  std::ofstream file(filepath);
  if (!file.is_open()) {
    std::cerr << "ERROR!!! I Can't open " << filepath << " to write" << std::endl;
  }

  std::string data = file_content;
  std::copy(data.begin(), data.end(), std::ostream_iterator<char>(file));
  file << std::endl;
  file.close();
}

TEST( FileInfoCompareStats, IsGreater) {
    //std::cout << "______    TESTS  _____"<< kMachinePath + "/machine1_test/file2" << std::endl;
    FileInfo first( fs::directory_entry{ kMachinePath + "/machine1_test/file6" }, "file6", "machine1_test" );
    FileInfo second( fs::directory_entry{ kMachinePath + "/machine3_test/file6" }, "file6", "machine3_test" );
    //std::cout << "______    TESTS  _____"<< first.getAbsolutePath() << std::endl;
    // FileInfo file_info( dir_entry );
    auto const check_option = SyncApp::CompareOption::Greater;
    EXPECT_EQ( check_option,  )
    // EXPECT_NE( 0, file_info.getFileSize() );
    // EXPECT_NE( 0, file_info.getModTime() );
    // EXPECT_NE( "", file_info.getPath() );
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