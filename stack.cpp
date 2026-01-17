// Author: William Marklynn/Yang Wen-li
// Desc: This file contains extension code to 'stack.h', providing definitions
//       for the methods that were declared in that file.

#include "stack.h"
#include <iostream>
#include <cassert>

// desc: default constructor of class 'Stack'
// pre:  - none
// post: - member 'size' is initialized to 0
//       - member 'head' is pointing to null
Stack::Stack() {
    size = 0;
    head = nullptr;
}

// desc: copy constructor of class 'Stack'
// pre:  - instance 'other' follows all invariants of class 'Stack'
// post: - state of instance 'other' copied into a newly constructed
//         instance of 'stack'
//       - does not access memory out of bounds
//       - does not dereference null pointers
//       - does not access uninitialised values
Stack::Stack(Stack const &other) {
    Node* iter = other.head;
    size = other.size;
    head = new Node;
    Node* copy_iter = head;
    while (iter != nullptr) {
        copy_iter -> value = iter -> value;
        if (iter -> next == nullptr) {
            copy_iter -> next = nullptr;
        } else {
            copy_iter -> next = new Node;
        }
        iter = iter -> next;
        copy_iter = copy_iter -> next;
    }
}

// desc: overloaded assignment operator of class 'Stack'
// pre:  - 'this' instance of Stack follows all invariants of the class
//       - 'other' instance follows all invariants of the class
//       - member 'head' of instance 'other' has to point at a non-empty
//         linked list
// post  - state of instance 'other' assigned to instance 'this', creating
//         an independent copy of 'other'
//       - does not leak memory
//       - does not access memory out of bounds
//       - does not access uninitialized values;
//       - does not dereference null pointers
const Stack& Stack::operator=(Stack const &other) {
    if (other.head != nullptr && this != &other) {
        deallocate_list();
        Node* iter= other.head;
        size = other.size;
        head = new Node;
        Node* copy_iter = head;
        while (iter != nullptr) {
            copy_iter -> value = iter -> value;
            if (iter -> next == nullptr) {
                copy_iter -> next = nullptr;
            } else {
                copy_iter -> next = new Node;
            }
            iter = iter -> next;
            copy_iter = copy_iter -> next;
        }
    }
    return *this;
}

// desc: method that deallocates linked list pointed by member 'head'. Works
//       in conjunction with overloaded assignment operator and destructor
// pre:  - instance follows all invariants of class 'Stack'
// post: - linked list of dynamic nodes deallocated
//       - does not leak memory
//       - does not access memory out of bounds
//       - does not dereference null pointers
//       - does not access uninitialized values
void Stack::deallocate_list() {
    Node *iter = head;
    while (iter != nullptr) {
        head = iter -> next;
        delete iter;
        iter = head;
    }
}

// desc: - push method that pushes a new value into the current state of the
//         stack
//       - adding a new dynamically allocated node to the end of the stack
// pre:  - instance follows all invariants of class 'Stack'
// post: - new value added to the top of the stack
//       - new node added to the end of the linked list
//       - does not access memory out of bounds
//       - does not dereference null pointers
//       - does not access uninitialized values
//       - size is incremented by 1 to reflect new size of the stack/list
void Stack::push(int value) {
    size++;
    Node* temp = new Node {value, head};
    if (temp) {
        head = temp;
    }
}

// desc: - prints/outputs current state of the stack with its values separated
//         by commas
// pre:  - instance follows all invariants of class 'Stack'
// post: - current state of the stack outputted
//       - does not access memory out of bounds
//       - does not dereference null pointers
//       - does not access uninitialized values
void Stack::print_state() {
    Node* iter = head;
    while (iter != nullptr) {
        if (iter -> next != nullptr) {
            std::cout << iter -> value << ", ";
        } else {
            std::cout << iter -> value;
        }
        iter = iter -> next;
    }
    std::cout << std::endl;
}

// desc: - removes most recently added value from the stack and returns the
//         value
//       - in linked list terms: removes the last node of the list and returns
//         the value it was holding
// pre:  - instance follows all invariants of class 'Stack'
//       - stack is not empty
// post: - run time error thrown if stack is empty
//       - size is decremented by 1
//       - most recently added value is removed from the stack
//       - removed value is returned
//       - does not access memory out of bounds
//       - does not leak memory
//       - does not dereference null pointers
//       - does not access uninitialized values
int Stack::pop() {
    if (is_empty()) {
      throw std::runtime_error(std::string("Stack is empty. Please push"
        " value(s) into stack before calling pop method."));
    } else {
        size--;
        int value = 0;
        Node *temp = head;
        value = temp -> value;
        head = head -> next;
        return value;
    }
}

// desc: - checks if Stack is empty. Returns true if yes, returns false
//         otherwise
//       - in linked list terms: checks if 'head' is pointing to null
//       - works in conjunction with 'pop' method
// pre:  - instance follows all invariants of class 'Stack'
// post: - true is returned if stack is empty
//       - false is returned if stack not empty
bool Stack::is_empty() {
    return !size;
}

// desc: - destructor
//       - linked list of dynamically allocated nodes deallocated
// pre:  - instance of stack follows all invariants of the class
// post: - instance destructed
//       - linked list of dynamically allocated nodes deallocated
//       - does not leak memory
Stack::~Stack() {
    deallocate_list();
}
