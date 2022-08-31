#pragma once

#include "Command.hpp"

class SettingApp : public Command {
public:
    SettingApp();
    ~SettingApp() = default;

    void operator()( std::vector< FileInfo >const& file ) override;

    private:
};