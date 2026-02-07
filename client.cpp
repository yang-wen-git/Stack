// Author: William Marklynn
// Desc:   This file contains testing code to test the methods of class
//         'Stack'. Testing code are categorized into individual functions
//         and additional functions that help execute/verify functionality of
//         the methods.

#include "stack.h"
#include <iostream>

void pop_test(Stack &demo_stack);

Stack copy_test(Stack &demo_stack);

void assign_test(Stack &demo_stack, Stack &copy_stack);

void independent_test(Stack &demo_stack, Stack &copy_stack);

void push_test(Stack &demo_stack);

int main() {
    Stack active_state;


    std::cout << "Pop test function: " << std::endl;
    pop_test(active_state);
    std::cout << std::endl;

    std::cout << "Push test function: " << std::endl;
    push_test(active_state);
    std::cout << std::endl;

    std::cout << "Pop test function: " << std::endl;
    pop_test(active_state);
    std::cout << std::endl;

    std::cout << "One more call to pop test function: " << std::endl;
    pop_test(active_state);
    std::cout << std::endl;

    std::cout << "Copy constructor test function: " << std::endl;
    Stack copy_stack = copy_test(active_state);
    std::cout << "Checking if both stacks are independent..." << std::endl;
    independent_test(active_state, copy_stack);
    std::cout << std::endl;

    std::cout << "Overloaded assignment operator test function: "
    << std::endl;
    assign_test(active_state, copy_stack);

    return 0;
}


// desc: function to test the pop method of stack. Try block to attempt to
//       pop the stack. Run time error statement from pop method is caught
//       if the stack is empty
// pre:  parameter 'demo_stack' follows all invariants of class Stack
// post: - most recently added value in 'demo_stack' is popped from the stack
//       - popped value is outputted
//       - new state of 'demo_stack' is outputted
//       - if 'demo_stack' is empty, run time error thrown by pop method is
//         outputted
void pop_test(Stack &demo_stack) {
    int val;
    try {
        val = demo_stack.pop();
        std::cout << "Popped value: " << val << std::endl;
        std::cout << "Updated stack: " << std::endl;
        demo_stack.print_state();
    } catch (std::exception & err) {
        std::cerr << err.what() << std::endl;
    }
}

// desc: function to test the push method of stack. Integer values 0-10 are
//       pushed to the stack via a for loop. Current state of the stack is
//       printed through each iteration of the for loop. After the for loop,
//       completed stack is outputted
// pre:  parameter 'demo_stack' follows all invariants of class Stack
// post: - Integar values 0-10 pushed to 'demo_stack'
//       - updated state of 'demo_stack' outputed
void push_test(Stack &demo_stack) {
    for (int i = 0; i < 11; i++) {
        std::cout << "Pushing " << i << " into stack..." << std::endl;
        demo_stack.push(i);
        demo_stack.print_state();
    }
    std::cout << "Updated stack: " << std::endl;
    demo_stack.print_state();
}

// desc: function to test the copy constructor of stack. A new instance of
//       Stack is constructed using Stack's copy constructor, with
//       'demo_stack' passed as an argument.
// pre:  parameter 'demo_stack' follows all invariants of class Stack
// post: - independent copy of instance 'demo_stack' is returned
Stack copy_test(Stack &demo_stack) {
    Stack saved_state(demo_stack);
    std::cout << "Copy stack: " << std::endl;
    saved_state.print_state();
    return saved_state;
}

// desc: - function to test whether 'demo_stack' and 'copy_stack' independent
//       - to be called after an instance of Stack has been constructed using
//         Stack's copy constructor or after an assignment operator of Stack
//         has been called.
// pre:  - parameter 'demo_stack' follows all invariants of class Stack
//       - parameter 'copy_stack' follows all invariants of class Stack
// post: - integer value '17' is pushed into 'demo_stack'
//       - most recently added value in 'copy_stack' is popped
//       - state of 'demo_stack' and 'copy_stack' are outputted to verify
//         if both instances are independent copies
void independent_test(Stack &demo_stack, Stack &copy_stack) {
    std::cout << "Pushing 17 into original stack..." << std::endl;
    demo_stack.push(17);
    std::cout << "Popping copy stack..." << std::endl;
    copy_stack.pop();
    std::cout << "Original stack: " << std::endl;
    demo_stack.print_state();
    std::cout << "Copy stack: " << std::endl;
    copy_stack.print_state();
}

// desc: - function to test the overloaded assignment operator method of
//         Stack
// pre:  - parameter 'demo_stack' follows all invariants of class Stack
//       - parameter 'copy_stack' follows all invariants of class Stack
// post: - state of 'demo_stack' is copied into 'copy_stack'
//       - 'copy_stack' is now an independent copy of 'demo_stack'
//       - function 'independent_test' is called to verify both are
//         independent copies of each other
void assign_test(Stack &demo_stack, Stack &copy_stack) {
    copy_stack = demo_stack;
    std::cout << "Original stack: " << std::endl;
    demo_stack.print_state();
    std::cout << "Copy stack: " << std::endl;
    copy_stack.print_state();
    std::cout << "Verifying independence of the two stacks... " << std::endl;
    independent_test(copy_stack, demo_stack);
}
