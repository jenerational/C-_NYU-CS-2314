//
//  main.cpp
//  Lec_06
//  stacks aka fuk me up
//
//  Created by Jennifer Walker on 3/7/17.
//  Copyright (c) 2017 Jennifer Walker. All rights reserved.
//


/*
 stack: 
    first one in, last one out (think like being shoved to the back of an elevator)
    only have access to the first element of the stack
 stack operations:
    push (add to the stack)
    pop (remove from top of stack)
    top (see the first element - only one you can see)
    is empty (is the stack empty?)
    clearn (clear the stack one by one)
    ** no square brackets!!! 
 ** how can you store the stack (enormous amt of data) in main memory? (is an STL stack but ignoring for now)
    -> cant do map, set --> would be reordered 
    -> use a vector? 
        -> how long for...
            -   push: O(1) or O(n) (-> if the array has room, it's constant; if the array's run out of room we have to copy over the whole vector)
            -   pop: O(1) (constant)
            -   top: O(1) (constant)
            -   isEmpty: O(1) (constant)
            -   clear: O(1) (constant)
    -> use a list? 
        ->  how long for...
            -   push: O(1) (constant, items are linked to each other through pointers, doesnt matter where they're stored in main memory)
            -   pop: O(1) (constant)
            -   top: O(1) (constant)
            -   isEmpty: O(1) (constant)
            -   clear: O(n) (have to go element by element, depends on num of elements)
 
 */
#include <iostream>
#include <vector>
#include <list>

using namespace std;

class Stack {
    list<T> data;
public:
    void push(T newdata);
    T pop();
    T& top();
    T top() const;
    bool isEmpty() const {return data.begin() == data.end(); }
    void clear() {data.clear();}
};

template <class T>
T Stack<T>::top() const {
    return *data.begin();
}

int main() {
    /*
     Associativity is the order of operations of operators of the same precidence level

     *  postfix form doesnt have parenthesis because it doesn't need them.
     CONVERT FROM INFIX TO POSTFIX: (stack stores operators (*^+))
     1) If the input is an operand, ouput it
     2) if the input is an open parens, push it on the stack
     3) if the input is a closed parens, pop to output all elements until the open parens, (throw away the open)
     4) if the input is an operator,
        a) if the precedence of the incoming operator is higher than that of the one on the top of the stack, push the incoming operator.
        b) if the precedence is lower, pop to output, until you can push, then push the incoming operator.
        c) if the precidenece is equal,
            i) if associativiity is left to right use 'b' above 
            ii) if associativity is right to left, use 'A' above
     
     ** anthing can be pushed on top of an open parenthesis 
     CONVERT POSTFIX TO OUTPUT VALUE: (stack stores operands (234))
     1) if the input is an operand, Push it on the stack
     2) if the input is an operator, pop two items and perform the operation, remember that the second item popped is the left hand side of the peration. Push the result. 
     3) when input is finished, the value will be on the top of the stack.
     
     */
}




