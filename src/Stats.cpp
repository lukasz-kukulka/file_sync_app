#include "Stats.hpp"

namespace SyncApp {
    CompareOption getCompareOption( FileInfo* const lhs, FileInfo* const rhs ) {
        if( ( not lhs || not rhs ) || ( lhs->getPath() != rhs->getPath() ) ) {
            return CompareOption::Different;
        }
        if ( lhs->getAbsolutePath() == rhs->getAbsolutePath() ) {
            return CompareOption::Equal;
        } else {
            if ( lhs->getModTime() != rhs->getModTime() ) {
                if ( lhs->getModTime() != rhs->getModTime() && lhs->getModTime() > rhs->getModTime() ) {
                    return CompareOption::Greater;
                } else if ( lhs->getModTime() != rhs->getModTime() && lhs->getModTime() < rhs->getModTime() ) {
                    return CompareOption::Less;
                }
            } 
        }
        return CompareOption::None;
    }

    template<typename... Args>
    FileInfo* compareFilesInfo( const Args*... args ) {
        FileInfo* newest_file = nullptr;
        for (auto const& info : { args... } ) {
            auto const compare_result = getCompareOption( newest_file, info );
            switch ( compare_result ) {
                case CompareOption::Different :
                case CompareOption::Equal :
                    return nullptr;
                case CompareOption::Greater :
                    return newest_file;
                case CompareOption::Less :
                    return info;
                default:    
                    std::cout << "ERROR WRONG VALUE IN COMPARE FUNCTION\n"; 
                    return nullptr;
            }
        }
        return nullptr;
    }


} // namespace SyncApp