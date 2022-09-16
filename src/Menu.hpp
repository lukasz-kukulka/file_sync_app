#pragma once
#include <string>
class Menu {
public:
    Menu( );

    void runMenu();
private:
    void switchOption( int const choice );
    void printMenu() const;

    std::string main_path_{};
};