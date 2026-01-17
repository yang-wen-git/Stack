// Author: William Marklynn/Yang Wen-li
// Desc:   The file contains the declaration of class 'Stack' and its methods.
//         Stack of integer values will be implemented via linked lists. Thus,
//         class member 'head' will be pointing to a linked list composed of
//         instances of struct Node. Methods are defined in 'stack.cpp'
// Invariants: member 'head' is either pointing at null or at an instance
//             of struct Node. Member 'size' is an integer to reflect the
//             size of the stack
#include <iostream>

struct Node {
    int value;
    Node* next;
};

class Stack {
    private:
    int size;
    Node* head;

    public:
    Stack();
    Stack(Stack const &other);
    const Stack& operator=(Stack const &other);

    void deallocate_list();
    void push(int value);
    void print_state();

    int pop();

    bool is_empty();

    ~Stack();
};
