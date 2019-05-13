// Workshop 1 - Linkage, Storage Duration, Namespaces, and OS Interface
//  String.h
//  ws1
//
//  Created by Anmol Sandhu on 2019-05-08.



#ifndef String_h
#define String_h

#include <iostream>

namespace sict {
    
    class String{
        char istr[4];
    public:
        String(const char *);
        void display(std::ostream&) const;
    };
    
    std::ostream & operator<<(std::ostream& os, String& i);
}
#endif /* String_h */
