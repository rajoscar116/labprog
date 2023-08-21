#include <iostream>
using namespace std;

// Define the Node structure
struct Node {
    int data;
    Node* prev;
    Node* next;
};

// Define the DoublyLinkedList class
class DoublyLinkedList {
private:
    Node* head;
    Node* tail;

public:
    // Constructor
    DoublyLinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    // Insert a new element at the beginning of the list
    void insertAtBeginning(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->prev = nullptr;
        newNode->next = head;
        
        if (head != nullptr) {
            head->prev = newNode;
        } else {
            tail = newNode; // If list was empty, newNode becomes tail
        }

        head = newNode;
    }

    // Display the elements in the list
    void display() {
        Node* current = head;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

int main() {
    DoublyLinkedList myList;

    // Insert elements into the doubly linked list
    myList.insertAtBeginning(10);
    myList.insertAtBeginning(20);
    myList.insertAtBeginning(30);

    // Display the doubly linked list
    cout << "Doubly Linked List elements:" << endl;
    myList.display();

    return 0;
}

