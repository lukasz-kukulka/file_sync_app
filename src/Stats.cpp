#include "Stats.hpp"
namespace SyncApp {
    // CompareOption getCompareOption( std::optional< FileInfo > const& lhs, FileInfo const& rhs ) {
    //     if( ( not lhs.has_value() ) || ( lhs.value().getPath() != rhs.getPath() ) ) {
    //         return CompareOption::Different;
    //     }
    //     if ( lhs.value().getAbsolutePath() == rhs.getAbsolutePath() ) {
    //         return CompareOption::Equal;
    //     } else {
    //         if ( lhs.value().getModTime() != rhs.getModTime() ) {
    //             if ( lhs.value().getModTime() != rhs.getModTime() && lhs.value().getModTime() > rhs.getModTime() ) {
    //                 return CompareOption::Greater;
    //             } else if ( lhs.value().getModTime() != rhs.getModTime() && lhs.value().getModTime() < rhs.getModTime() ) {
    //                 return CompareOption::Less;
    //             }
    //         }
    //     }
    //     return CompareOption::None;
    // }
    CompareOption getCompareOption( FileInfo* lhs, FileInfo* rhs ) {
        std::cout << "\n" << lhs->getModTime() << " L ? R " << rhs->getModTime() << std::endl; 

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