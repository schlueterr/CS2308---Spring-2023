#ifndef DYNINTSTACK_h
#define DYNINTSTACK_h
#include <iostream>
using namespace std;

// Use question 2 from StackInClassPractice.pdf as a pick up point
class DynIntStack{
    private:
        struct Node{
            int data;
            Node *next;
        };
        Node *head;

    public:
        DynIntStack() { head = nullptr; }
        ~DynIntStack();
        void push(int);
        int pop();
        bool isFull() const { return false; }
        bool isEmpty() const { return head == nullptr; }

};

#endif