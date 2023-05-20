#include "Stats.hpp"
namespace SyncApp {
    CompareOption getCompareOption( FileInfo* lhs, FileInfo* rhs ) {
        if( ( not lhs ) || ( lhs->getPath() != rhs->getPath() ) ) {
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

    

} // namespace SyncApp