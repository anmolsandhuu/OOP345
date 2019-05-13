// Workshop 1 - Linkage, Storage Duration, Namespaces, and OS Interface
// w1.cpp
// Chris Szalwinski
// 2019/01/08
//
//  ws1
//
//  Created by Anmol Sandhu on 2019-05-08.



#include <iostream>
#include "process.h"

 int INITIAL = 3;

int main(int argc, char * argv[]) {
    
    std::cout <<" Command Line: ";
    
    if(argc < 2 ){
        std::cout << "***Insufficient number of arguments***" << std::endl;
        return 1;
    }
    for( int i = 0; i <= argc; ++i ){
        std::cout << argv[i] << ' ';
        std::cout<< std::endl;
    }
  
    
    for(int i = 0; i <= argc; ++i){
        sict::process(argv[i]);
    }
    return 0;
}
