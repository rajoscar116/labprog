#include <iostream>
using namespace std;

const int maxSize = 100; // Maximum size of the queue

class Queue {
private:
    int arr[maxSize];
    int front, rear; // Indices for front and rear of the queue

public:
    // Constructor
    Queue() {
        front = -1; // Queue is initially empty
        rear = -1;
    }

    // Enqueue (add) an element to the back of the queue
    void enqueue(int value) {
        if (rear == maxSize - 1) {
            cout << "Queue overflow. Cannot enqueue element." << endl;
            return;
        }
        if (front == -1) {
            front = 0; // If queue was empty, set front to 0
        }
        arr[++rear] = value;
    }

    // Dequeue (remove) an element from the front of the queue
    void dequeue() {
        if (front == -1) {
            cout << "Queue underflow. Cannot dequeue element." << endl;
            return;
        }
        if (front == rear) {
            // If only one element is left, reset front and rear
            front = rear = -1;
        } else {
            front++;
        }
    }

    // Get the front element of the queue
    int peek() {
        if (front == -1) {
            cout << "Queue is empty." << endl;
            return -1; // Return a sentinel value
        }
        return arr[front];
    }

    // Check if the queue is empty
    bool isEmpty() {
        return front == -1;
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

