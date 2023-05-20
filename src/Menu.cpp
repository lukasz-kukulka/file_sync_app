#include "Menu.hpp"

#include "MachinesSync.hpp"
#include "ExitApp.hpp"
#include "SettingApp.hpp"
#include <iostream>

Menu::Menu() {
    main_path_ = fs::current_path().parent_path().string();
}

void Menu::runMenu() {
    //SyncApp::systemInfoInit();
    auto menu_choice = SyncApp::MenuOption::None;
    while ( menu_choice != SyncApp::MenuOption::Exit ) {
        std::string choice{};
        printMenu();

        std::getline( std::cin, choice );
        menu_choice = switchOption( validateAndConvertInput( choice ) );
    }
}

SyncApp::MenuOption Menu::switchOption( int const choice ) {
    auto menu_choice = SyncApp::MenuOption::None;
    switch ( static_cast< SyncApp::MenuOption > ( choice ) ) {   
        case SyncApp::MenuOption::SyncMachines :
            menu_choice = SyncApp::MenuOption::SyncMachines;
            command_ = std::make_unique< MachinesSync >( main_path_ );
            break;
        case SyncApp::MenuOption::Settings :
            command_ = std::make_unique< SettingApp >();
            menu_choice = SyncApp::MenuOption::Settings;
            break;
        case SyncApp::MenuOption::Exit :
            menu_choice = exitDecision();
            if ( menu_choice == SyncApp::MenuOption::Exit ) {
                command_ = std::make_unique< ExitApp >();
            }
            break;
        default:

            menu_choice = SyncApp::MenuOption::None;
            break;
    }

    if (command_) {
        (*command_)( file_prev_settings_ );
        command_ = nullptr;
    }
    return menu_choice;
}

void Menu::printMenu() const {
    int menu_num { 1 };
    std::cout << "SYNC APP\n";
    std::cout << menu_num++ << ". Synchronize machines\n";
    std::cout << menu_num++ << ". Settings\n";
    std::cout << menu_num++ << ". Exit\n";
}

void Menu::printConfirmExit() const {
    std::cout << "Are you sure you want quit SYNC APP Y/N ";
}

SyncApp::MenuOption Menu::exitDecision() {
    printConfirmExit();
    char decision{};
    auto menu_decision = SyncApp::MenuOption::None;
    std::string possible_options{ "YyNn" }; 
    do {
        std::cin >> decision;
        if ( decision == 'Y' || decision == 'y' ) {
            menu_decision = SyncApp::MenuOption::Exit;
        } else if ( decision == 'N' || decision == 'n' ) {
            menu_decision = SyncApp::MenuOption::None;
        } else {
            std::cout << "Wrong answer\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    } while ( std::ranges::none_of( possible_options, [ decision ]( auto character ){ return decision == character; } ) );
    return menu_decision;
}

int Menu::validateAndConvertInput(std::string const& input) {
    std::string player_right_choice{};
    for ( auto const& character : input ) {
        if ( std::isdigit( character ) ) {
            player_right_choice.push_back( character );
        }
        if ( player_right_choice.size() >= 2 ) {
            break;
        }
    }
    if ( not player_right_choice.empty() ) {
        return std::stoi( player_right_choice );
    } else {
        return 100;
    }
}
