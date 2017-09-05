//
//  main.cpp
//  Exam 2 Review
//
//  Created by Jennifer Walker on 3/9/17.
//  Copyright (c) 2017 Jennifer Walker. All rights reserved.
//

#include <iostream>
#include <vector>
#include <map>
#include <cfloat>

using namespace std;

/*
 Q1: "Unsorted array of n integers"
    - 82% had an inefficient algorithm
    - could have simply used quicksort 
    - some people defaulted min to 0
    - people should have used absolute value
 */

int q1 (vector<int> v) {
    sort(v.begin(), v.end());   //  default is quicksort
    int minDist = INT_MAX;
    for (int i = 1; i < v.size(); i++) {
        if (abs(v[i] - v[i-1]) < minDist) {
            minDist = abs(v[i] - v[i-1]);
        }
    }
    return minDist;
}

/*
 Q2: "metro multimap"
    - appropriate iterator / USING an iterator
    - multimap for the return
    - correct use of first and second
*/
vector<int> q2(multimap<char, int>& m, char c) {
    vector<int> retval;
    for (multimap<char, int>::iterator i = m.begin(); i != m.end(); i++) {
        if (i->first == c) {
            retval.push_back(i->second);
        }
    }
    return retval;
}

/*
 Q3: "heterosexual relations work when pair are close in height"
 -  "sum of all the difference of all the couples is the minimum that it can be " 
 -  was done in two ways:
    - find max or min -> move to back and then pop back (reordering, no go, but no pop backs)
    - change last used to DOUBLE_MAX and find the max each time
 */

vector<pair<double, double>> q3a(vector<double> m, vector <double> w) {
    vector<pair<double, double>> retval;
    for (int i = 0; i < m.size(); i++) {
        //  set to 0 because indeces
        int minMan = 0;
        int minWoman = 0;
        for (int j = 1; j < m.size(); j++ ) {
            if (m[j] < m[minMan]) {
                minMan = j;
            }
        }
        for (int j = 1; j < w.size(); j++ ) {
            if (m[j] < w[minWoman]) {
                minWoman = j;
            }
        }
        pair<double, double> temp(m[minMan], w[minWoman]);
        m[minMan] = DBL_MAX;
        w[minWoman] = DBL_MAX;
        retval.push_back(temp);
    }
    return retval;
}

//  Q3b: O(n^2)

vector<pair<double, double>> q3c(vector<double> m, vector <double> w) {
    sort(m.begin(), m.end());
    sort(w.begin(), w.end());
    vector<pair<double, double>> retval;
    pair<double, double> couple;
    for (int i = 0; i < m.size(); i++)  {
        couple.first = m[i];
        couple.second = w[i];
        retval.push_back(couple);
    }
    return retval;
}

//  Q3d: O(n log n)
//      -> not a linear function because it includes the call to quicksort, which is n log n

//  Q4a: median of three portion is the if statements -> O(1)

//  Q4b: basically the worst case algorithm ->

//  Q5a: wanted to see the dereference of the pointer
class Elephant {
    int size;
public:
    bool operator<(const Elephant& rhs) {
        return size < rhs.size;
    }
};

void q5a(vector<Elephant*>& v) {      // O(n^2)
    for (int i=1; i < v.size(); i++) {
        Elephant* temp = v[i];
        int j = i;
        for (j = i; j > 0 && *(temp)<*(v[j-1]); j--) {
            v[j] = v[j-1];
        }
        v[j] = temp;
    }
}

void q5b (vector <Elephant*>& v) {
    vector<Elephant*> vep;
    for (int i = 0; i < v.size(); i++) {
        vep.push_back(v[i]);
    }
    /* could also sort w for each --> need *
     for (Elephant& e : v) {
        vep.push_back(&e)
     }
     */
    q5a(vep);
    //  need temp bc all the pointers point to elephants in v 
    vector<Elephant> temp;
    for(Elephant* ptr : vep) {
        temp.push_back(*ptr);
    }
    v = temp;
}

//  Q5b:
//  "by the time i got to q 5b i was so sad and drunk - i didnt say that - i was so sad i didnt want to look at the question"
//  "If you turn your hand and look at the results sideways its indicative of how this exam went"
//  different from 5a because you're sorting elephants not the pointers to the elephants
//  **  needed to copy the results to a temporary vector  **


int main() {
    //
}



