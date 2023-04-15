#pragma once

#include "Command.hpp"
#include "Stats.hpp"

#include <string>

class Menu {
public:
    Menu( );

    void runMenu();
private:
    SyncApp::MenuOption switchOption( int const choice );
    void printMenu() const;
    void printConfirmExit() const;
    SyncApp::MenuOption exitDecision();
    int validateAndConvertInput( std::string const& input );

    std::string main_path_{};
    std::unique_ptr< Command >command_;
    std::vector< FileInfo > file_prev_settings_;
};