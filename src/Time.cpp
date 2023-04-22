#include "Time.hpp"

namespace MainTime {
    std::time_t getFileTime( fs::directory_entry const& file ) {
        auto file_time = file.last_write_time();
        auto f_sys_time = std::chrono::file_clock::to_sys( file_time );
        return std::chrono::system_clock::to_time_t( f_sys_time );
    }

    std::time_t getFileTimeHighPrecision( fs::directory_entry const& file ) {
        auto file_time = file.last_write_time();
        auto f_sys_time = std::chrono::file_clock::to_sys( file_time );
        auto f_time_us = std::chrono::time_point_cast<std::chrono::microseconds>( f_sys_time );
        return f_time_us.time_since_epoch().count();
    }


} //namespace MainTime