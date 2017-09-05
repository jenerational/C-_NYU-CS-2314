//
//  main.cpp
//  Lec_04
//
//  Created by Jennifer Walker on 2/21/17.
//  Copyright (c) 2017 Jennifer Walker. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

template <class T>
void selectionSort(vector<T>& v){ //O(N^2)
    for (int i = 0; i < v.size(); i++){
        int min = i;
        for (int j = i + 1; j < v.size(); j++)
            if (v[j] < v[min])
                min = j;
        T temp = v[i];
        v[i] = v[min];
        v[min] = temp;
    }
}

template <class T>
void insertionSort(vector<T>& v){ //O(N^2)
    for (int i = 1; i < v.size(); i++){
        T temp = v[i];
        int j = i;
        for (j = i; j > 0 && v[j - 1] > temp; j--)
            v[j] = v[j - 1];
        v[j] = temp;
    }
}

template <class T>
void shellSort(vector<T>& v){
    for (int gap = v.size() / 2; gap > 0; gap /= 2)
        for (int i = gap; i < v.size(); i++){
            T temp = v[i];
            int j = i;
            for (; j >= gap && temp < v[j - gap]; j -= gap)
                v[j] = v[j - gap];
            v[j] = temp;
        }
}


template <class T>
void mergeSort(vector<T>& v, int start, int end, vector<T>& temp){
    int mid = (start + end) / 2;
    if (end <= start)
        return;
    mergeSort(v, start, mid, temp);
    mergeSort(v, mid + 1, end, temp);
    merge(v, start, mid, end, temp);
}
template <class T>
void mergeSort(vector<T>& v){
    vector<T> temp;
    temp.resize(v.size());
    mergeSort(v, 0, v.size() - 1, temp);
}


int main(int argc, const char * argv[]) {
    // insert code here...
}
