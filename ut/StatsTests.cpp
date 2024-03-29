#include <gtest/gtest.h>
#include "../src/FileInfo.hpp"
#include "../src/Stats.hpp"
#include <fstream>
#include <string>
#include <thread>

namespace fs = std::filesystem;

std::string const kMachinePath = static_cast< std::string > ( fs::current_path().parent_path().string() ) + "/ut/MachinesTest";
fs::directory_entry const kDirEntry( kMachinePath );

void createTestFile( std::string const& file_name, std::string const& file_content ) {
    std::string const filepath = kMachinePath + file_name;
    std::ofstream file( filepath );
    if ( !file.is_open() ) {
        std::cerr << "ERROR!!! I Can't open " << filepath << " to write" << std::endl;
    }

    std::string data = file_content;
    std::copy( data.begin(), data.end(), std::ostream_iterator<char>( file ) );
    file.close();
}


void generateTestMachine( std::string const& machine_name, int const machine_num, std::string const& file_name, bool const is_reverse_name = false ) {
    for ( int i{}; i < machine_num; i++ ) {
        std::string const postfix = is_reverse_name ? machine_name + std::to_string( machine_num - i ) : machine_name + std::to_string( i + 1 );
        std::string const machine_directory = machine_name + std::to_string( i + 1 );
        std::this_thread::sleep_for( std::chrono::microseconds( 1 ) );
        fs::create_directory( kMachinePath + machine_directory );
        createTestFile( machine_directory + file_name, "test xxxx" );
    }
}

void deleteTestMachines() {
    for (auto const& file : fs::directory_iterator{ kMachinePath } ) {
        fs::remove_all( file );
    }
}

TEST( FileInfoCompareStatsTest, IsGreater ) {
    std::string const file_name = "/test_file_1" ;
    std::string const machine_name = "/M_greater_test_";

    generateTestMachine( machine_name, 2, file_name );

    FileInfo first( fs::directory_entry{ kMachinePath + machine_name + "1" + file_name  }, file_name, machine_name );
    FileInfo second( fs::directory_entry{ kMachinePath + machine_name + "2" + file_name }, file_name, machine_name );
    auto const check_option = SyncApp::CompareOption::Greater;

    EXPECT_EQ( check_option, SyncApp::getCompareOption( &second, &first ) );

    deleteTestMachines();
}

TEST( FileInfoCompareStatsTest, IsGreaterReverseName ) {
    std::string const file_name = "/test_file_1" ;
    std::string const machine_name = "/M_greater_test_";

    generateTestMachine( machine_name, 2, file_name, true );

    FileInfo first( fs::directory_entry{ kMachinePath + machine_name + "1" + file_name  }, file_name, machine_name );
    FileInfo second( fs::directory_entry{ kMachinePath + machine_name + "2" + file_name }, file_name, machine_name );
    auto const check_option = SyncApp::CompareOption::Greater;

    EXPECT_EQ( check_option, SyncApp::getCompareOption( &second, &first ) );

    deleteTestMachines();
}

TEST( FileInfoCompareStatsTest, IsLess ) {
    std::string const file_name = "/test_file_1" ;
    std::string const machine_name = "/M_less_test_";

    generateTestMachine( machine_name, 2, file_name );

    FileInfo first( fs::directory_entry{ kMachinePath + machine_name + "1" + file_name  }, file_name, machine_name );
    FileInfo second( fs::directory_entry{ kMachinePath + machine_name + "2" + file_name }, file_name, machine_name );
    auto const check_option = SyncApp::CompareOption::Less;

    EXPECT_EQ( check_option, SyncApp::getCompareOption( &first, &second ) );

    deleteTestMachines();
}

TEST( FileInfoCompareStatsTest, IsLessReverseName ) {
    std::string const file_name = "/test_file_1" ;
    std::string const machine_name = "/M_less_test_";

    generateTestMachine( machine_name, 2, file_name, true );
    
    FileInfo first( fs::directory_entry{ kMachinePath + machine_name + "1" + file_name  }, file_name, machine_name );
    FileInfo second( fs::directory_entry{ kMachinePath + machine_name + "2" + file_name }, file_name, machine_name );
    auto const check_option = SyncApp::CompareOption::Less;

    EXPECT_EQ( check_option, SyncApp::getCompareOption( &first, &second ) );

    deleteTestMachines();
}

TEST( FileInfoCompareStatsTest, IsEqual) {
    std::string const file_name = "/test_equal_1" ;
    std::string const machine_name = "/M_less_test_";

    generateTestMachine( machine_name, 1, file_name );

    FileInfo first( fs::directory_entry{ kMachinePath + machine_name + "1" + file_name  }, file_name, machine_name );
    FileInfo second( fs::directory_entry{ kMachinePath + machine_name + "1" + file_name }, file_name, machine_name );
    auto const check_option = SyncApp::CompareOption::Equal;

    EXPECT_EQ( check_option, SyncApp::getCompareOption( &first, &second ) );

    deleteTestMachines();
}

TEST( FileInfoCompareStatsTest, IsDifferent) {
    std::string const first_file_name = "/test_different_1" ;
    std::string const second_file_name = "/test_different_2" ;
    std::string const machine_name = "/M_less_test_";

    generateTestMachine( machine_name, 1, first_file_name );
    generateTestMachine( machine_name, 1, second_file_name );

    FileInfo first( fs::directory_entry{ kMachinePath + machine_name + "1" + first_file_name  }, first_file_name, machine_name );
    FileInfo second( fs::directory_entry{ kMachinePath + machine_name + "1" + second_file_name }, second_file_name, machine_name );
    auto const check_option = SyncApp::CompareOption::Different;

    EXPECT_EQ( check_option, SyncApp::getCompareOption( &first, &second ) );

    deleteTestMachines();
}

TEST( FileInfoCompareStatsTemplateTest, IsFileInfoToChange ) {
    std::string const file_name = "/test_compare_1" ;
    std::string const machine_name = "/M_change_test_";
    generateTestMachine( machine_name, 4, file_name );

    FileInfo first( fs::directory_entry{ kMachinePath + machine_name + "1" + file_name  }, file_name, machine_name );
    FileInfo second( fs::directory_entry{ kMachinePath + machine_name + "2" + file_name }, file_name, machine_name );
    FileInfo third( fs::directory_entry{ kMachinePath + machine_name + "3" + file_name  }, file_name, machine_name );
    FileInfo fourth( fs::directory_entry{ kMachinePath + machine_name + "4" + file_name }, file_name, machine_name );

    FileInfo const test_file_info = fourth;
    
    auto* const result1 = SyncApp::compareFilesInfo( &first, &second, &third, &fourth );
    auto* const result2 = SyncApp::compareFilesInfo( &fourth, &first, &second, &third );
    auto* const result3 = SyncApp::compareFilesInfo( &first, &fourth, &second, &third );
    auto* const result4 = SyncApp::compareFilesInfo( &first, &second, &fourth, &third );

    EXPECT_EQ( test_file_info.getAbsolutePath(), result1->getAbsolutePath() );
    EXPECT_EQ( test_file_info.getAbsolutePath(), result2->getAbsolutePath() );
    EXPECT_EQ( test_file_info.getAbsolutePath(), result3->getAbsolutePath() );
    EXPECT_EQ( test_file_info.getAbsolutePath(), result4->getAbsolutePath() );

    EXPECT_EQ( test_file_info.getModTime(), result1->getModTime() );
    EXPECT_EQ( test_file_info.getModTime(), result2->getModTime() );
    EXPECT_EQ( test_file_info.getModTime(), result3->getModTime() );
    EXPECT_EQ( test_file_info.getModTime(), result4->getModTime() );

    deleteTestMachines();
}