#include <iostream>

class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = nullptr;
    }
};

class CircularLinkedList {
private:
    Node* head;

public:
    CircularLinkedList() {
        head = nullptr;
    }

    // Function to insert a new node at the end of the list
    void insert(int value) {
        Node* newNode = new Node(value);

        if (head == nullptr) {
            head = newNode;
            head->next = head; // Point the only node back to itself
        } else {
            Node* current = head;
            while (current->next != head) {
                current = current->next;
            }
            current->next = newNode;
            newNode->next = head; // Point the new node back to the head
        }
    }

    // Function to display the contents of the list
    void display() {
        if (head == nullptr) {
            std::cout << "List is empty!" << std::endl;
            return;
        }

        Node* current = head;
        do {
            std::cout << current->data << " ";
            current = current->next;
        } while (current != head);
        std::cout << std::endl;
    }

    // Function to delete a node with a given value from the list
    void remove(int value) {
        if (head == nullptr)
            return;

        if (head->data == value) {
            Node* temp = head;
            Node* current = head;
            while (current->next != head) {
                current = current->next;
            }
            current->next = head->next;
            head = head->next;
            delete temp;
        } else {
            Node* current = head;
            Node* prev = nullptr;
            do {
                prev = current;
                current = current->next;
            } while (current != head && current->data != value);

            if (current != head) {
                prev->next = current->next;
                delete current;
            }
        }
    }

    // Function to check if a value exists in the list
    bool search(int value) {
        if (head == nullptr)
            return false;

        Node* current = head;
        do {
            if (current->data == value) {
                return true;
            }
            current = current->next;
        } while (current != head);

        return false;
    }

    // Function to clear the list and free memory
    void clear() {
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    ~CircularLinkedList() {
        clear();
    }
};

int main() {
    CircularLinkedList list;
    list.insert(10);
    list.insert(20);
    list.insert(30);
    list.display();

    list.remove(20);
    list.display();

    std::cout << "Search 30: " << (list.search(30) ? "Found" : "Not Found") << std::endl;
    std::cout << "Search 40: " << (list.search(40) ? "Found" : "Not Found") << std::endl;

    list.clear();

    return 0;
}

