#include "Menu.hpp"

#include "MachinesSync.hpp"
#include "ExitApp.hpp"
#include <iostream>

Menu::Menu() {
    std::string main_path_ = fs::current_path().parent_path();
    std::cout << main_path_;
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
            
            menu_choice = SyncApp::MenuOption::Settings;
            break;
        case SyncApp::MenuOption::Exit :
            command_ = std::make_unique< ExitApp >();
            menu_choice = SyncApp::MenuOption::Exit;
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
