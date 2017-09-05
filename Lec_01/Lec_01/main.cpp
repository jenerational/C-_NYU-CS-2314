//
//  main.cpp
//  Lec_01
//  1124 REVIEW 1/24 AND 1/26
//
//  Created by Jennifer Walker on 1/24/17.
//  Copyright (c) 2017 Jennifer Walker. All rights reserved.
//

/*
 Pre Notes Notes:
 - dont need to buy the book but there will be problems from it for more HW 
    - book does have pdf copies
    - book was written by mathmatician , hence all the proofs (that we do not need)
 - last time for 1124 and 2314!
 - exams are open book!! open notes!! but NOT open laptop. Only printed material
     - exams will be during class time
     - questions wont be harder but you'll have to go beyond rote (sp?) learning
        - goes memorization, rote learning, actual understanding 
        - aka nothing like what does a node class look like but how do we use it for a stack or queue
 
 1114: just get the code to run
 1124: get the code to run correctly
 2134: get the code to run correctly and *efficiently* 
 
 Tips: memorize 2^x when x is 8 or less, 2^32, 2^64
 
 Pythod Code to look at:
 
 def func1(15):
    ls=[5];
 
 def func2(ls):
    ls.append(5);
 
 def main();
 15=[];
 //func1(ls); --> prints empty list (passes list pointer, then creates a whole new list)
 func2(ls); --> prints out 5 (passes list pointer and append manipulates the actual list)
 print(ls);
 
 What We Need To Review ("What are we not comfortable?")
 - STL/iterators -- will review later
 - linked lists -- will be covering extensively later
 - inheritance, polymorphism    // Note doing Either! of these
 - file i/o
 - pointers
 - Big 3
 - arrays 
 */


#include <iostream>
#include <fstream>

using namespace std;

//  Student class made on 1/26 @ 3:02 pm
class Student {
public:
    int id;
    int* testscores;
};

//  sayHello made on 1/26 @ 3:22 pm; openInputfile made on 1/26 @ 3:23
void sayHello(ostream& outs) {
    outs << "Hello World!" << endl;
}

//  someClass made on 1/26 @ 3:34 pm
class someClass {
    int * temp;
public:
    someClass() : temp(new int(0)){}
    virtual ~someClass(){ delete temp; }        //  *?? v
    someClass (const someClass& rhs) { *temp = *rhs.temp;}
    someClass& operator=(const someClass& rhs);
};

someClass& someClass::operator=(const someClass& rhs) {
    if (this != &rhs) {
        delete temp;
        temp = new int(*rhs.temp);
    }
    return *this;
}

void openInputFile(ifstream& inFile) {
    string filename;
    cout << "Open what filename? ";
    cin >> filename;
    inFile.open(filename);
    while (!inFile) {
        cout << "Bad Filename!" << endl;        //  cout vs cerr for error *??
        cout << "Open what filename? ";
        inFile.clear();                     //  need clear bc if there was a failed opening once it will still register as an error even if the second attempt to open was successful
        inFile.open(filename);
    }
}


int main() {
    //                                      POINTERS
    int x = 100;
    int* y = &x;
    *y = 200;
    cout << x << endl;
    // ^^ above prints "200" bc the address of x is set to 200. There is only one int here and that is x.
    
    // biggest limit for a 32 bit os is the amount of RAM the comp can have bc each byte has to have its address and the address has to be unique
    
   /* 
    3 errors with pointers
    1) Defreference nullptr;      -->     program will completely crash
    - ex: int *x = nullptr;
    - not always as obvious as blatantly dereferencing, can happen accidentally
    2) Double delete
    - cant delete a pointer twice
    - ex:
        int* x = new int;
        int* y = x;
        delete x;
        delete y;           //  y points to the same integer, thus the double delete. It's like calling a box by two names and then trying to remove the same thing from it twice
    3) Garbage on the heap / memory leak (same thing)
    - when you have memory left on the heap that you can no longer access
    - ex:
        int* x = new int;
        x = other new int;
        delete x;           //  new int is still left on the heap that you can't access - will never find it again
    - how they usually show up:
    - something starts up and runs for long time (ex: months). When a program ends, all the memory used goes back into the system, but if the program is continuously running, the memory never gets deleted
    - crashes every couple of months bc even though its fine when it starts (only using a few megs), there are small memory leaks that add up into multiple memory leaks (gigs, etc) and eventually the computer cannot allocate more memory to the program and crashes 
    
    ** Katz doesn't care about dangling pointers -> its bad style but not a programming error
    */

    
    //                                     THURS 1/26 Notes
    // new & delete -> every time you call new, you have to call delete. new delete ratio = 1:1. If they don't match up there is either a double delete or a memory leak
    
    x = 150;    //  created on the stack -> created on an activation record for main -> call stack *??
                //  scope of x is in the function main (where it was created). Lifetime of the variable is the lifetime of the function
    y = new int(0); //  created on the heap -> has no organization, just a bunch of junk in memory. We can organize the info in the heap with pointers. Only destroyed by delting, no other way
                //  scope of variable does not exist, lifetime is exactly what you say it is.
    *y = 100;
    delete y;   //  dangling pointer -> el chapo is dead but the camera is still pointing to where he was
                //  we can reuse y - we dont have to throw away the camera just bc el chapo was killed in front of it
    cout << *y << endl; //  whether we can print out y still matters whether or not were in deep og mode (where y is deleted) or whether youre in release mode (been marked for deletion). This can be exploited in web browsers as a means of bypassing security if passwords are stored in clear text
    y = nullptr; // removes the dangling pointer -> safety mechanism, otherwise y is just pointing at garbage
    
    //  Student class made at this point in time
    //  we will be working w arrays a lot this semester, need to know them
    //  two types: stack dynamic array and heap dynamic array
    //  - stack dynamic array size is static - cannot be changed
    //  c++ does not keep track the size of an array, that's the programmer's job
    
    Student *sptr;
    sptr = new Student;
    sptr ->id = 1000;
    sptr -> testscores = new int [3];
    sptr -> testscores[0] = 100;
    sptr -> testscores[1] = 90;
    sptr -> testscores[2] = 95;
    //delete sptr; // deleted the student object, but the object contains the pointer to an array -> memory leak
    //  worth it to draw out sptr, the student, the scores, etc. Can get credit on an exam for a correctly drawn diagram.
    delete[] sptr->testscores;      //  deletes the entrie array.
    delete sptr;    //  left w dangling pointer
    
    
    //                      DYNAMIC ARRAYS
    
    //  why we start at position 0:
    //      4 bits per address.  Start of element = base of array + (size of 1 * index)
    //                              *arr == arr[0]
    
    //  z is one address but you can store 100 things in it... how?
    //      - element base =                    --> start of array = 0 bc base of array is at position 0
    //          - base of array +               --> pointer!
    //          - index* size of one element    --> known based on one data type
    //  the base of the array is a pointer, which is why when you pass an array to a function by value, the changes are still there -> you're passing a pointer, so when you edit something , youre editing actual data in the pointer location

    //  cannot use non const for a stack array
    int z = 100;    // *?? -> what is error?
    //int arr[z];
    
    const int w = 100;
    int arr2[w];
    
    
    
    //                  FILE I/O
    
    //  sayHello & openInputFile functions created here
    
    ifstream inFile;
    openInputFile(inFile);
    int iarr[50];
    double darr[50];
    int count;
    while (count < 50 && inFile >> iarr[count]) {
        inFile >> darr[count];
        count++;
    }
    
    ofstream outFile;
    outFile.open("output.txt");
    sayHello(outFile);
    sayHello(cout);
    
    
    //              BIG 3
    
    //  class someClass made here
    
    
}







