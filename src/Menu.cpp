#include "Menu.hpp"
#include "Stats.hpp"
Menu::Menu() {
    
}

void Menu::runMenu() {
    int choice{};
    printMenu();
    std::cin >> choice >> '\n';
    try {
        switchOption( choice );
    } catch (const std::out_of_range const& exception) {
        std::cerr << "Exception: " << exception.what() << std::endl;
    }
}

void Menu::switchOption( int const choice ) {
    switch ( static_cast< SyncApp::MenuOption > ( choice + 1 ) ) {   
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

Menu::printMenu() const {
    int menu_num { 1 };
    std::cout << "SYNC APP\n";
    std::cout << menu_num++ << ". Synchronize machines\n";
    std::cout << menu_num++ << ". Settings\n";
    std::cout << menu_num++ << ". Exit\n";
}
