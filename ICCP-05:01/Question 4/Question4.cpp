#include <iostream>
#include <queue>

using namespace std;

class Stack {
private:
    queue<int> queue1;
    queue<int> queue2;

public:
    void push(int num) {
        queue1.push(num);
    }

    int pop() {
        int result;
        while (queue1.size() > 1) {
            queue2.push(queue1.front());
            queue1.pop();
        }
        result = queue1.front();
        queue1.pop();
        queue1.swap(queue2);
        return result;
    }

    bool isEmpty() {
        return (queue1.empty() && queue2.empty());
    }

    int size() {
        return queue1.size() + queue2.size();
    }
};

int main() {
    Stack s;

    // Push some elements onto the stack
    s.push(10);
    s.push(20);
    s.push(30);

    cout << "Size of stack: " <<  s.size() << endl; // 3
    
    
    // Pop elements from the stack
    while (!s.isEmpty()) {
        cout << s.pop() << " ";
    }

    return 0;
}
