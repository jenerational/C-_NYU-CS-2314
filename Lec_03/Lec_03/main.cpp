//
//  main.cpp
//  Lec_03 - Big O
//
//  Created by Jennifer Walker on 2/2/17 & 2/7/17
//  Copyright (c) 2017 Jennifer Walker. All rights reserved.
//

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

//  90% of decisions -> waste memory vs wasting cpu cycles

// whatever size your input is, multiply it by 10, because that's what it's going to be

/* Big O: 
 - measurment of underestimation of how long it will take for the task to be complete
 - generally dependent on input size rather than the algorithm 
 - tries to model what happens between input size of n and input size of (n+1) 
    - how does the process change based on a minor increase of the input size
 
 Big [Theta]
 - exact estimation of what we have to do
 */

class Point { // point ona  2d Scale
public:
    Point(int newx, int newy) : x(newx), y(newy) {}
    int x, y;
};

double distance(Point a, Point b) {
    return sqrt(((a.x-b.x)*(a.x-b.x)) + (a.y-b.y)*(a.y-b.y));
}

int closestToOrigin(vector<Point> pv) {
    //  given a vector of points, determine which point is closest to the origin (0, 0)
    Point origin(0,0);
    double min = distance(origin, pv[0]);
    int closest = 0;
    for (int i = 1; i < pv.size(); i++) {
        double thisDist = distance(origin, pv[i]);  //  saves result = saving CPU cycles by using memory; Big O is linear (O(n))
        if (thisDist < min) {
            closest = i;
            min = thisDist;
        }
    }
    return closest;
}

double closestPoints(vector<Point> v) {     //  O(Nn^2), Quadratic 
    double minDist = distance(v[0], v[1]);
    for (int i = 0; i < v.size(); i++) {
        for (int j = i+1; j < v.size(); j++) {
            double thisDist = distance(v[1], v[j]);
            if (thisDist < minDist) {
                minDist = thisDist;
            }
        }
    }
    return minDist;
}

//  mcss created 3:13 on 2/7; mcss2 created 3:18 on 2/7
int mcss(vector<int> v) {       //  O(n^3)
    int maxSum = 0;
    for (int i = 0; i < v.size(); i++) {
        for (int j = i; j < v.size(); j++) {
            int sum = 0;
            for (int k = 0; k <= j; k++) {
                sum += v[k];
            }
            if (sum > maxSum) {
                maxSum = sum;
            }
        }
    }
    return maxSum;
}

int mcss2(vector<int> v) {      //  O(n^2)
    int maxSum = 0;
    for (int i = 0; i < v.size(); i++) {
        int sum = 0;
        for (int j = i; j < v.size(); j++) {
            sum += v[j];
            if (sum > maxSum) {
                maxSum = sum;
            }
        }
    }
    return maxSum;
}

int mcss3(vector<int> v) {      //  O(N)
    int maxSum = 0;
    int sum = 0;
    for (int i = 0; i < v.size(); i++) {
        sum += v[i];
        if (sum > maxSum) {
            maxSum = sum;
        }
        else if (sum <=0) {
            sum = 0;
        }
    }
    return maxSum;
}

// func func created at 3:45pm on 2/7
void func(vector<int> v) {       //  O(n^2)
    int total = 0;
    for (int i = 0; i < v.size(); i++) {
        for (int j = i; j < v.size(); j++) {
            if (i == j) {
                for (int k=0; k < v.size(); k++) {
                    total += v[k];          //  CLOC -> runs n times within loop, outer loop also runs n times, thus, CLOC in total runs n^2 times
                }
            }
        }
    }
}


//  fib func created at 3:53pm on 2/7
int fib(int n) {    //  2^n -> exponential -> fib of time
    if (n < 2) {
        return 1;
    }
    return fib(n-1) + fib(n-2);
}


//  timer class and func2 func created at 4:09pm on 2/7

class Timer {
private:
    double start;
public:
    Timer() {start = clock();}
    double elapsed() {return (clock()-start) / CLOCKS_PER_SEC; }
    void reset() { start = clock(); }
};

// put func 2 here 

//                                          MAIN
int main() {
    int n = 100;
    for (int i = 0; i < n; i++) {
        // time = x; When n = 101, time is an additional 1%, or x.0x; n = 200, time is 2x; With a for loop, there is a linear progression.
        // the time it takes to run this code is O(n)
        cout << i << endl;          //  controlling line of code (CLOC) -> line of code that is going to run most frequently and the one that is going to change w the input size
    }
    
    vector<int> v;
    
    int dups = 0;
    for (int i = 0; i < v.size(); i++) {            //  n
        for (int j = i+1; i < v.size(); j++) {      //  n-1
            if (v[i]==v[j]) {                       //  CLOC
                dups++;                             //  (n(n-1)/2   ->  Big [theta]
            }
            /*__n___|__CLOC__
                2   |   1
                3   |   3
                4   |   6
                5   |   10              dif of 2, dif of 3, dif for 4 -> not linear!
             */
             
        }
        //  finding duplicates in a vector take O(n^2)
    }
    cout << "There are " << dups << " duplicates." << endl;
    
    /* Big O is important bc if you're dealing w an array of a million items, a Binary search (logarithmic -> O(log(2)n)) would take about 20 passes vs a linear search which would take, on average, half a million */
    
    //  class Point, func distance, func closestToOrigin, and fun closest Points created here
    
    // to find if a point c is on a line, it requires 3 nested loops --> O(n^3)
    
    /*  BEST TO WORST FOR BIG O
     O(1) - constant
     O(log N) - logarithmic (ex: binary search) --> log & n log n only happen when repeated halving/doubling
     O(N) - linear
     O(N log N)
     O(N^2) - quadratic
     O(N^3) - cubic
     ... (etc)
     O(2^n) - Exponential
     */
    
    /* Maximum Contiguous Subsequence Sum (MCSS Algorithm/Problem)
     Given a set (or vector) of numbers (pos and neg) what is the maximum sum? It is important to note that because the numbers must be continguous, one cannot just simply remove all the negative numbers.
     
     */
    //  mcss func & mcss2 & mcss3 func created here
    
    //  func func created here
    
    //  fib func created here
    
    //  func2 func and timer class created here
    
}






