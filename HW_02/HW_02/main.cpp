//
//  main.cpp
//  HW_02
//
//  Created by Jennifer Walker on 3/1/17.
//  Copyright (c) 2017 Jennifer Walker. All rights reserved.
//

#include <iostream>

class Timer{
private:
    double start;
public:
    Timer(){ start = clock(); }
    double elapsed(){ return (clock() - start) / CLOCKS_PER_SEC; }
    void reset(){ start = clock(); }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
