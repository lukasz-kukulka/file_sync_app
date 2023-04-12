#pragma once

#include "FileInfo.hpp"
#include <vector>
class Command {
public:
    virtual ~Command() = default;
    virtual void operator()( std::vector< FileInfo >const& file )  = 0;
};