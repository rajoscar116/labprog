#include <iostream>
using namespace std;

// Define the Node structure
struct Node {
    int data;
    Node* next;
};

// Define the SinglyLinkedList class
class SinglyLinkedList {
private:
    Node* head;

public:
    // Constructor
    SinglyLinkedList() {
        head = nullptr;
    }

    // Insert a new element at the beginning of the list
    void insertAtBeginning(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = head;
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
    SinglyLinkedList myList;

    // Insert elements into the linked list
    myList.insertAtBeginning(10);
    myList.insertAtBeginning(20);
    myList.insertAtBeginning(30);

    // Display the linked list
    cout << "Linked List elements:" << endl;
    myList.display();

    return 0;
}

