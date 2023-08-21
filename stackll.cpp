#include <iostream>
using namespace std;

// Define the Node structure
struct Node {
    int data;
    Node* next;
};

// Define the Stack class
class Stack {
private:
    Node* top;

public:
    // Constructor
    Stack() {
        top = nullptr; // Stack is initially empty
    }

    // Push an element onto the stack
    void push(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = top;
        top = newNode;
    }

    // Pop an element from the stack
    void pop() {
        if (top == nullptr) {
            cout << "Stack underflow. Cannot pop element." << endl;
            return;
        }
        Node* temp = top;
        top = top->next;
        delete temp;
    }

    // Get the top element of the stack
    int peek() {
        if (top == nullptr) {
            cout << "Stack is empty." << endl;
            return -1; // Return a sentinel value
        }
        return top->data;
    }

    // Check if the stack is empty
    bool isEmpty() {
        return top == nullptr;
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

