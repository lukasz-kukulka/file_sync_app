#include "time.hpp"

namespace MainTime {
    std::time_t getFileTime( fs::directory_entry file ) {
        auto file_time = file.last_write_time();
        auto f_sys_time = std::chrono::file_clock::to_sys( file_time );
        return std::chrono::system_clock::to_time_t( f_sys_time );
    }
} //namespace MainTime