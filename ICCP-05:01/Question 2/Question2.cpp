#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool isBalanced(string expr) {
    stack<char> stack1;
    for (char c : expr) {
        if (c == '(' || c == '[' || c == '{') {
            stack1.push(c);
        } else if (c == ')' || c == ']' || c == '}') {
            if (stack1.empty()) {
                return false;
            } else if ((c == ')' && stack1.top() == '(') || 
                       (c == ']' && stack1.top() == '[') ||
                       (c == '}' && stack1.top() == '{')) {
                stack1.pop();
            } else {
                return false;
            }
        }
    }
    return stack1.empty();
}

int main() {
    string expr1 = "[ ( ) ]";
    string expr2 = "( ) [ ] { } ";
    string expr3 = "( { ) } ";
    
    cout << isBalanced(expr1) << endl; // true
    cout << isBalanced(expr2) << endl; // true
    cout << isBalanced(expr3) << endl; // false
    
    return 0;
}
