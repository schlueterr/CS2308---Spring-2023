#include "intStack.h"
#include <iostream>
using namespace std;

int main(){
    IntStack stack;
    stack.push(5);
    stack.push(10);
    stack.push(15);
    stack.push(20);

    stack.displayStack();
    stack.elementsInStack();

    cout << "Popping elements from the stack..." << endl;
    stack.pop();
    stack.pop();

    stack.elementsInStack();
    stack.displayStack();

    return 0;
}