#include <iostream>
using namespace std;

// Define the Node structure
struct Node {
    int data;
    Node* next;
};

// Define the CircularLinkedList class
class CircularLinkedList {
private:
    Node* head;

public:
    // Constructor
    CircularLinkedList() {
        head = nullptr;
    }

    // Insert a new element at the beginning of the list
    void insertAtBeginning(int value) {
        Node* newNode = new Node();
        newNode->data = value;

        if (head == nullptr) {
            newNode->next = newNode; // Point to itself in case of an empty list
        } else {
            Node* current = head;
            while (current->next != head) {
                current = current->next;
            }
            current->next = newNode;
            newNode->next = head;
        }

        head = newNode;
    }

    // Display the elements in the list
    void display() {
        if (head == nullptr) {
            cout << "Circular Linked List is empty." << endl;
            return;
        }

        Node* current = head;
        do {
            cout << current->data << " ";
            current = current->next;
        } while (current != head);
        cout << endl;
    }
};

int main() {
    CircularLinkedList myList;

    // Insert elements into the circular linked list
    myList.insertAtBeginning(10);
    myList.insertAtBeginning(20);
    myList.insertAtBeginning(30);

    // Display the circular linked list
    cout << "Circular Linked List elements:" << endl;
    myList.display();

    return 0;
}

