#include <iostream>
using namespace std;

class Stack {
private:
    static const int MAX_SIZE = 100;
    int arr[MAX_SIZE];
    int top;

public:
    Stack() {
        top = -1; 
    }

    bool isEmpty() {
        return top == -1;
    }

    void push(int value) {
        if (top == MAX_SIZE - 1) {
            cout << "Stack overflow. Cannot push element." << std::endl;
            return;
        }
        top++;
        arr[top] = value;
    }

    int pop() {
        if (isEmpty()) {
            cout << "Stack underflow. Cannot pop element." << std::endl;
            return -1;
        }
        int value = arr[top];
        top--;
        return value;
    }

    int peek() {
        if (isEmpty()) {
            cout << "Stack is empty. Cannot peek." << std::endl;
            return -1;
        }
        return arr[top];
    }
};

int main() {
    Stack stack;

    stack.push(10);
    stack.push(20);
    stack.push(30);

    cout << "Top element: " << stack.peek() << std::endl;

    while (!stack.isEmpty()) {
        cout << "Popped element: " << stack.pop() << std::endl;
    }

    cout << "Is stack empty? " << (stack.isEmpty() ? "Yes" : "No") << endl;


    return 0;
}
