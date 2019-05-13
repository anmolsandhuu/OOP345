// Workshop 1 - Linkage, Storage Duration, Namespaces, and OS Interface
//  String.cpp
//  ws1
//
//  Created by Anmol Sandhu on 2019-05-08.

#include<iostream>
#include <cstring>
#include "String.h"
extern int INITIAL;

namespace sict{
    
    String::String(const char * str){
        
        if(str == nullptr) {   // cheching if the string is nullptr
            istr[0] = '\0';    // storing as null
        }
        else {
            std::strncpy(istr, str, 3);  //copying first 3 char of string
            istr[3] = '\0';              // null at the end
        }
    }
    
    void String::display(std::ostream& os)const{
        os << istr;
    }
    
    std::ostream& operator<<(std::ostream& os, String& i) {
        
        os << INITIAL++ << ": ";
        i.display(os);
        return os;
    }
}
