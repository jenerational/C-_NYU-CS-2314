//
//  main.cpp
//  HW_01
//
//  Created by Jennifer Walker on 2/5/17.
//  Copyright (c) 2017 Jennifer Walker. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <map>
#include <vector>

using namespace std;


//                                  TASK 1
class ComboLock {
    int combo[3];
    bool opened;
public:
    ComboLock (int new1, int new2, int new3) : combo{new1, new2, new3}, opened(false) {}
    //  func opens lock
    bool open(int*& openAttempt) {
        for (size_t i = 0; i < 3; ++i) {
            if (openAttempt[i] != combo[i]) {
                cerr << "Lock combination was incorrect." << endl;
                return opened;
            }
        }
        opened = true;
        return opened;
    }
    //  func changes lock combo
    void comboChange(int*& comboAttempt, int*& newCombo) {
        for (size_t i = 0; i < 3; ++i) {
            if (comboAttempt[i] != combo[i]) {
                cerr << "Lock combination was incorrect." << endl;
                break;
            }
        }
        for (size_t i = 0; i < 3; ++i) {
            combo[i] = newCombo[i];
        }
    }
};


//                                  TASK 2
struct Node {
    a_type data;
    Node* link;
};

template <class a_type> class DynArray {
    a_type DAvar;
public:
    //
};

//                                  TASK 3
//  receives map with item data and vector of items purchased; returns double of total cost
double totalPrice (vector<int>& purchaseV, map<int, double>& invM) {
    double total = 0.00;
    for (int& itemNum : purchaseV) {
        if (invM.find(itemNum)!=invM.end()) {
            total += invM[itemNum];
        }
        else {
            cout << itemNum << " is not a purchasable item." << endl;
        }
    }
    return total;
}


int main() {
    //  file i/o
    ifstream infile("/Users/jwalks/Downloads/HW1data.txt");
    if (!infile) {
        cerr << "File not found." << endl;
        exit(1);
    }
    
    //  initiialize variables
    int itemNum;
    double itemPrice, purchaseTotal;
    map <int, double> invM;
    vector<int> purchaseV;
    
    while (infile >> itemNum >> itemPrice) {
        invM.insert(pair<int, double>(itemNum, itemPrice));
    }
    
    purchaseTotal = totalPrice(purchaseV, invM);
}





