#include "Menu.hpp"

#include "MachinesSync.hpp"
#include "ExitApp.hpp"
#include "SettingApp.hpp"
#include <iostream>

Menu::Menu() {
    std::string main_path_ = fs::current_path();
    std::cout << main_path_ << std::endl;
    MachinesSync machineSync{ main_path_ };
    machineSync.run();
}

void Menu::runMenu() {
    auto menu_choice = SyncApp::MenuOption::None;
    while ( menu_choice != SyncApp::MenuOption::Exit ) {
        int choice{};
        printMenu();
        std::cin >> choice;
        menu_choice = switchOption( choice );
    }
}

SyncApp::MenuOption Menu::switchOption( int const choice ) {
    auto menu_choice = SyncApp::MenuOption::None;
    switch ( static_cast< SyncApp::MenuOption > ( choice ) ) {   
        case SyncApp::MenuOption::SyncMachines :

            menu_choice = SyncApp::MenuOption::SyncMachines;
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
    //char possible_options[ 4 ] = { 'Y', 'y', 'N', 'n', }; 
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
