//
//  rubbishs.cpp
//  codesegments
//
//  Created by nine on 15/3/15.
//  Copyright (c) 2015年 nineteen. All rights reserved.
//

#include "rubbishs.h"

#include <iostream>

void stub(){
    
    
    
}

class Widget{
private:
    static int count;
public:
    Widget(){++count;}
    ~Widget(){--count;}
    int numWidgets(){return count;}
};

int Widget::count = 0;

void myf(){
    Widget w,x;
    std::cout<<w.numWidgets()<<" "<<x.numWidgets();
}