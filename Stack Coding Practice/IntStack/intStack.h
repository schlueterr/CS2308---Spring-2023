#ifndef INTSTACK_H
#define INTSTACK_H
class IntStack{
    private:
        static const int STACK_SIZE = 100;
        int stackArray[STACK_SIZE];
        int top;
    
    public:
        IntStack();
        void push(int);
        int pop();
        bool isEmpty() const;
        bool isFull() const;
        void elementsInStack() const;
        void displayStack() const;
};

#endif