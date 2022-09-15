#pragma once

#include "Command.hpp"

#include <string>
class Menu {
public:
    Menu( );

    void runMenu();
private:
    SyncApp::MenuOption switchOption( int const choice );
    void printMenu() const;

    std::string main_path_{};
    std::unique_ptr< Command >command_;
};