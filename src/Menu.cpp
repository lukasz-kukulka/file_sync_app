#include "Menu.hpp"

#include "MachinesSync.hpp"
#include "Stats.hpp"

#include <iostream>

Menu::Menu() {
    std::string main_path_ = fs::current_path().parent_path();
    std::cout << main_path_;
    MachinesSync machineSync{ main_path_ };
    machineSync.run();
}

void Menu::runMenu() {
    while ( true ) {
        int choice{};
        printMenu();
        std::cin >> choice;
        try {
            switchOption( choice );
        } catch (const std::out_of_range& exception) {
            std::cerr << "Exception: " << exception.what() << std::endl;
        }
    }
}

void Menu::switchOption( int const choice ) {
    switch ( static_cast< SyncApp::MenuOption > ( choice ) ) {   
        case SyncApp::MenuOption::SyncMachines :
            /* code */
            break;
        case SyncApp::MenuOption::Settings :
            /* code */
            break;
        case SyncApp::MenuOption::Exit :
            /* code */
            break;
        default:
            throw std::out_of_range("Wrong menu options");
            break;
    }
}

void Menu::printMenu() const {
    int menu_num { 1 };
    std::cout << "SYNC APP\n";
    std::cout << menu_num++ << ". Synchronize machines\n";
    std::cout << menu_num++ << ". Settings\n";
    std::cout << menu_num++ << ". Exit\n";
}
