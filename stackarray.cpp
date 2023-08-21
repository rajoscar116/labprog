#include <iostream>
using namespace std;

const int maxSize = 100; // Maximum size of the stack

class Stack {
private:
    int arr[maxSize];
    int top; // Index of the top element

public:
    // Constructor
    Stack() {
        top = -1; // Stack is initially empty
    }

    // Push an element onto the stack
    void push(int value) {
        if (top == maxSize - 1) {
            cout << "Stack overflow. Cannot push element." << endl;
            return;
        }
        arr[++top] = value;
    }

    // Pop an element from the stack
    void pop() {
        if (top == -1) {
            cout << "Stack underflow. Cannot pop element." << endl;
            return;
        }
        top--;
    }

    // Get the top element of the stack
    int peek() {
        if (top == -1) {
            cout << "Stack is empty." << endl;
            return -1; // Return a sentinel value
        }
        return arr[top];
    }

    // Check if the stack is empty
    bool isEmpty() {
        return top == -1;
    }
};

int main() {
    Stack myStack;

    myStack.push(10);
    myStack.push(20);
    myStack.push(30);

    cout << "Top element: " << myStack.peek() << endl;
    
    myStack.pop();
    
    cout << "Top element after pop: " << myStack.peek() << endl;

    return 0;
}

