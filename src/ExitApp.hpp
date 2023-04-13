#pragma once
#include "Command.hpp"
class ExitApp : public Command {
public:
    ExitApp();
    ~ExitApp() = default;
    void operator()(std::vector< FileInfo >const& file_info ) override;
private:
    
};