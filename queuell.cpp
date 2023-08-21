#include <iostream>
using namespace std;

// Define the Node structure
struct Node {
    int data;
    Node* next;
};

// Define the Queue class
class Queue {
private:
    Node* front;
    Node* rear;

public:
    // Constructor
    Queue() {
        front = nullptr; // Queue is initially empty
        rear = nullptr;
    }

    // Enqueue (add) an element to the back of the queue
    void enqueue(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = nullptr;

        if (rear == nullptr) {
            front = newNode;
            rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
    }

    // Dequeue (remove) an element from the front of the queue
    void dequeue() {
        if (front == nullptr) {
            cout << "Queue underflow. Cannot dequeue element." << endl;
            return;
        }
        Node* temp = front;
        front = front->next;
        delete temp;
    }

    // Get the front element of the queue
    int peek() {
        if (front == nullptr) {
            cout << "Queue is empty." << endl;
            return -1; // Return a sentinel value
        }
        return front->data;
    }

    // Check if the queue is empty
    bool isEmpty() {
        return front == nullptr;
    }
};

int main() {
    Queue myQueue;

    myQueue.enqueue(10);
    myQueue.enqueue(20);
    myQueue.enqueue(30);

    cout << "Front element: " << myQueue.peek() << endl;

    myQueue.dequeue();

    cout << "Front element after dequeue: " << myQueue.peek() << endl;

    return 0;
}

