//
//  main.cpp
//  HW_04
//
//  Created by Jennifer Walker on 4/25/17.
//  Copyright (c) 2017 Jennifer Walker. All rights reserved.
//

//  apologies for this being a mess

#include <iostream>
#include <unordered_map>

using namespace std;

template <class T>
class hashing {
    T obj;
public:
    int hash () {
        return obj % 10007;
    }
    bool operator!=(const T otherObj) {
        if (obj == otherObj) {
            return false;
        }
        return true;
    }
};

int main() {
    // insert code here...
    unordered_map<int, hashing, hashing.hash()> hashMap>
}







































'