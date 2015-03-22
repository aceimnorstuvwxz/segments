//
//  myrandom.cpp
//  codesegments
//
//  Created by nine on 15/3/15.
//  Copyright (c) 2015年 nineteen. All rights reserved.
//

#include "myrandom.h"
#include <iostream>
#include <random>
#include <array>
#include <string>
#include <vector>

void myrandom_ram(int x, const int size){
    std::cout<<x<<" ";
    unsigned seed = (unsigned)std::chrono::system_clock::now().time_since_epoch().count();
    const int size2 = 10;
    std::array<int, size2> foo;
    for (int j; j < size2; ++j) {
        foo[j] = j;
    }
    std::shuffle(foo.begin(), foo.end(), std::default_random_engine(seed));
    for (int& x : foo) std::cout<<" "<< x;
    std::cout<<std::endl;
}
void myrandom(){
    for (int x : {1,2,3,4}){
        myrandom_ram(x,100);
    }
}

