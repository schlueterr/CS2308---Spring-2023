#include "intStack.h"
#include <iostream>
using namespace std;

IntStack::IntStack(){
    top = -1;
}

void IntStack::push(int num){
    assert(!isFull());
    top++;
    stackArray[top] = num;
}

int IntStack::pop(){
    assert(!isEmpty());
    int num = stackArray[top];
    top--;
    return num;
}

bool IntStack::isEmpty() const{
    return (top == -1);
}

bool IntStack::isFull() const{
    return (top == STACK_SIZE - 1);
}

void IntStack::elementsInStack() const{
    int count = 0;
    for(int i = 0; i <= top; i++){
        count++;
    }
    cout << "There are " << count << " elements in the stack." << endl;
}

void IntStack::displayStack() const{
    for(int i = top; i >= 0; i--){
        cout << stackArray[i] << endl;
    }
}