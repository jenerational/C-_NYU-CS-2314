//
//  main.cpp
//  Lec_02
//  STL on 1/26 and 1/31
//
//  Created by Jennifer Walker on 1/26/17.
//  Copyright (c) 2017 Jennifer Walker. All rights reserved.
//

#include <iostream>
#include <vector>
#include <list>
#include <set>
#include <map>

using namespace std;


/*
 Standard Template Library (STL) is a library of all the data structures and algorithms that works across compiling programs (virtual studio, xcode, etc.) and very similar across languages (c++, java, etc; may have different names but basically the same functionality).
 
 We're going to figure out how to create everything in the STL and what to use when.
 
 Vector is the most basic STL data structure
 
 
 Useful container functions: (available on most of the container classes (vector, array, linked list, etc)); May change due to how the data is stored
    - empty (returns boolean of the state of the vector)
    - clear (empties the entire vector)
    - size (returns the size)
    - capacity
    - begin
    - end
 
 primary memory: RAM; secondary memory: harddrive; tertiary memory: cd, usb, etc;
 
                               FILE SYSTEMS
 Reason why transferring files between macs and pcs are annoying
 
 HFS+ - mac file system
 NTFS / REFS - windows file system
 FAT32 - both file system
 - stores blocks (kb in size) in the form of a linked list.
 - the last few bytes of each block is reserved for a pointer to the next block
 - which is why it has to load when you start off in the middle bc it needs to access all the blocks bc of the sequential access
 
 
 Make sure to use good variable names even though Katz doesn't
*/


//  func made at 4:17pm on 1/26
void func(const list<int>& ls) {
    for (list<int>::const_iterator i = ls.begin(); i != ls.end(); i++) {
        cout << *i << endl;
        // *i += 2;
    }
}

// class made at 3:09 pm on 1/31
template <class T, class S>
class Pair {
public:
    T first;
    S second;
};



int main() {
    //                                  VECTORS
    
    /* Vector insert functions (are only on the end):
    - push_back
        - cannot do a push_front because c++ thinks because it's too inefficient because by adding something to the front, we would have to move everything back by one
    - pop_back
    Vector access functions:
    - iterators
    - forward only
    - bidrectional
    - random access
    
    *??
    reverse iterator
    const iterator */
     
     
    vector <int> v;
    for (int i = 0; i < 100; i++) {
        v.push_back(i*10);
    }
    
    cout << v[3] << endl;       // [] is your random access iterator, and it doesn't take any more time to access the 3rd element than it does to access the 100th element
    
    //                                  LISTS
    
    /* List insert/removal functions (can be anywhere)
     - push_back
     - push_front
        - can do push_front efficiently because all we need to know is the pointer to the first element of the list which is easy enough to change
     - pop_back
     - pop_front
     - insert
     
     List iterators
     - cannot use square brackets (no random access iterator, only sequential)
     - reverse iterators
        - start at the last one and ++ to the first one 
            - could also use a regular iterator and do --
     
     end of the list is after the last item in the list -> not null
     l.end is like a dummy to say this is the end of the list.
     */
    
    list<int> ls;
    for (int i = 0; i < 100; i++) {
        ls.push_front(i*10);
    }
    
    for (list<int>::iterator i = ls.begin(); i != ls.end(); i++) {
        cout << *i << endl;
    }
    
    list<int>::iterator temp = ls.end();
    temp--;         //     temp is now pointing to the last item in the list
    cout << *temp;
    
    for (list<int>::reverse_iterator ri = ls.rbegin(); ri != ls.rend(); ri++) {
        cout << *ri << endl;
    }
    
    // func function made here
    
    
    
    //                          1/31
    
    //                          CLASS PAIRS
    //  pair class made here
    
    Pair <string, int> P;
    P.first="Daniel";
    P.second=100;
    //  pairception: can store 4 things of differing data types
    Pair <Pair<string, int>,Pair<char, float>> p2;
    p2.first.first="John";
    
    int x = 100, y = 10, z = 5;
    cout << ((x>z)?(x>y)?x:((y>z)?y:z):y) << endl;
    /* cout << (x < y)?x:y;
        vv
     if *??
     
     */
    
    //                          SETS
    /*
     Set properties (sort of marries vector and linked list)
     - fast insertions
     - fast searches
        - not as fast as inserting into a list but much faster than inserting into a vector
     - random insertion points
     - keeps everything in "sorted" order
        - sorts automatically
     - automatically eliminates duplicates 
        - could theoretically insert 100 random ints and get back 1 
     - cant use pointers in a set
     
     
     //                         MULTISETS
     ** in the same library as the set
     is the same as a set, except it stores duplicates
     --> if you need to sort a vector, you can chuck it into a multi set and that will sort it, which is efficient in terms of CPU time, though not in memory
     */
    
    set <int> S;
    for (int i = 0; i < 100; i++) {
        S.insert(rand()%1000);
    }
    for (int i:S) {
        cout << i << " ";
    }
    cout << endl;
    
    
    //                          MAPS
    /*
     - ties together a set and a pair
     - similar to dictionaries in python (aka key and associated value)
        - pair's first is a "key"
        - pair's second is a value" 
        - also knows as "associative arrays" in other languages
     - the map keys are always kept in sorted order
     
     also a thing called multimap?? --> but no sq brackets operator overload
     */
    
    map <string, int> m;
    m.insert(pair<string,int>("John",100));
    m.insert(pair<string,int>("David",90));
    m.insert(pair<string,int>("Albert",80));
    //  square brackets operator is overloaded for the map
    m["Daniel"]=105;
    m["Jennifer"]=110;
    
    //  able to sort letters lexicographically (alphabetically w capitalization)
    
    for (map<string,int>::iterator i=m.begin(); i!=m.end(); i++) {
        cout << i -> first << "=" << i-> second << endl;
    }
    //  square brackets operator is overloaded w printing too
    cout << "Jennie's score is " << m["Jennifer"] << endl;
    cout << m["Betty"] << endl;     //  prints garbage, but Betty is now created
    cout << m.size() << endl;               //  size is now 6
    
    //  check to see if thing exists before printing in order to avoid creation error
    if (m.find("Betty")!=m.end()) {
        cout << m["Betty"] << endl;     //  prints the garbage
    }pp
    if (m.find("Bettey")!=m.end()) {
        cout << m["Bettey"] << endl;    //  does not print anything bc not found
    }
    
    

}







