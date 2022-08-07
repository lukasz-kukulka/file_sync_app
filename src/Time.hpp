#pragma once
#include <filesystem>

namespace fs = std::filesystem;

namespace MainTime {

    std::time_t getFileTime( fs::directory_entry const& file );
    std::time_t getFileTimeHighPrecision( fs::directory_entry const& file );

} // namespace Time