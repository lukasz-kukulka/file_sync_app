#pragma once
#include <filesystem>

namespace fs = std::filesystem;

namespace MainTime {

    std::time_t getFileTime( fs::directory_entry file );


} // namespace Time