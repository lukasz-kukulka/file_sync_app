#pragma once

#include "FileInfo.hpp"
#include <vector>
#include <memory>
class Command {
public:
    virtual ~Command() = default;
    virtual void operator()(std::vector< FileInfo> >const& person )  = 0;
};